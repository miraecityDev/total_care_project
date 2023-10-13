"""
user_management.py

This module provides functionality for creating users and storing them in a JSON file.
"""
import json
import os
from passlib.context import CryptContext


# Password hashing context setup
pwd_context = CryptContext(schemes=["bcrypt"], deprecated="auto")


# Function to create a user and store it in a JSON file
def create_user(new_username, new_password):
    """
    Create a user and store them in a JSON file.

    Args:
        new_username (str): User ID.
        new_password (str): User password.
    """
    try:
        # Check if there is existing user information and initialize it as an empty list if not
        users_file = "./lib/users.json"
        if os.path.exists(users_file):
            with open(users_file, "r", encoding="utf-8") as file:
                users = json.load(file)
        else:
            users = {"user": []}

        # Check if the username already exists
        for user_data in users["user"]:
            if user_data["id"] == new_username:
                # Update the hashed password for the existing user
                user_data["password"] = pwd_context.hash(new_password)
                print(f"Password for user '{new_username}' has been updated.")
                break
        else:
            # Create user information as a dictionary and hash the password
            user_data = {
                "id": new_username,
                "password": pwd_context.hash(new_password)
            }

            # Add user information
            users["user"].append(user_data)
            print(f"User '{new_username}' has been created.")

        # Save user information to the JSON file
        with open(users_file, "w", encoding="utf-8") as file:
            json.dump(users, file, indent=4)
        return True
    except Exception as err:
        print(err)
        return False


if __name__ == "__main__":
    # Prompt for the username and password to create a user
    username = input("Enter username: ")
    password = input("Enter password: ")

    # Call the create user function
    create_user(username, password)
