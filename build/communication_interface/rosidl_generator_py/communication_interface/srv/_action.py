# generated from rosidl_generator_py/resource/_idl.py.em
# with input from communication_interface:srv/Action.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_Action_Request(type):
    """Metaclass of message 'Action_Request'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
    }

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('communication_interface')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'communication_interface.srv.Action_Request')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__action__request
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__action__request
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__action__request
            cls._TYPE_SUPPORT = module.type_support_msg__srv__action__request
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__action__request

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class Action_Request(metaclass=Metaclass_Action_Request):
    """Message class 'Action_Request'."""

    __slots__ = [
        '_cmd_code',
        '_cmd_value',
    ]

    _fields_and_field_types = {
        'cmd_code': 'string',
        'cmd_value': 'string',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.cmd_code = kwargs.get('cmd_code', str())
        self.cmd_value = kwargs.get('cmd_value', str())

    def __repr__(self):
        typename = self.__class__.__module__.split('.')
        typename.pop()
        typename.append(self.__class__.__name__)
        args = []
        for s, t in zip(self.__slots__, self.SLOT_TYPES):
            field = getattr(self, s)
            fieldstr = repr(field)
            # We use Python array type for fields that can be directly stored
            # in them, and "normal" sequences for everything else.  If it is
            # a type that we store in an array, strip off the 'array' portion.
            if (
                isinstance(t, rosidl_parser.definition.AbstractSequence) and
                isinstance(t.value_type, rosidl_parser.definition.BasicType) and
                t.value_type.typename in ['float', 'double', 'int8', 'uint8', 'int16', 'uint16', 'int32', 'uint32', 'int64', 'uint64']
            ):
                if len(field) == 0:
                    fieldstr = '[]'
                else:
                    assert fieldstr.startswith('array(')
                    prefix = "array('X', "
                    suffix = ')'
                    fieldstr = fieldstr[len(prefix):-len(suffix)]
            args.append(s[1:] + '=' + fieldstr)
        return '%s(%s)' % ('.'.join(typename), ', '.join(args))

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        if self.cmd_code != other.cmd_code:
            return False
        if self.cmd_value != other.cmd_value:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def cmd_code(self):
        """Message field 'cmd_code'."""
        return self._cmd_code

    @cmd_code.setter
    def cmd_code(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'cmd_code' field must be of type 'str'"
        self._cmd_code = value

    @builtins.property
    def cmd_value(self):
        """Message field 'cmd_value'."""
        return self._cmd_value

    @cmd_value.setter
    def cmd_value(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'cmd_value' field must be of type 'str'"
        self._cmd_value = value


# Import statements for member types

# already imported above
# import builtins

# already imported above
# import rosidl_parser.definition


class Metaclass_Action_Response(type):
    """Metaclass of message 'Action_Response'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
    }

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('communication_interface')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'communication_interface.srv.Action_Response')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__action__response
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__action__response
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__action__response
            cls._TYPE_SUPPORT = module.type_support_msg__srv__action__response
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__action__response

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class Action_Response(metaclass=Metaclass_Action_Response):
    """Message class 'Action_Response'."""

    __slots__ = [
        '_message',
    ]

    _fields_and_field_types = {
        'message': 'string',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.message = kwargs.get('message', str())

    def __repr__(self):
        typename = self.__class__.__module__.split('.')
        typename.pop()
        typename.append(self.__class__.__name__)
        args = []
        for s, t in zip(self.__slots__, self.SLOT_TYPES):
            field = getattr(self, s)
            fieldstr = repr(field)
            # We use Python array type for fields that can be directly stored
            # in them, and "normal" sequences for everything else.  If it is
            # a type that we store in an array, strip off the 'array' portion.
            if (
                isinstance(t, rosidl_parser.definition.AbstractSequence) and
                isinstance(t.value_type, rosidl_parser.definition.BasicType) and
                t.value_type.typename in ['float', 'double', 'int8', 'uint8', 'int16', 'uint16', 'int32', 'uint32', 'int64', 'uint64']
            ):
                if len(field) == 0:
                    fieldstr = '[]'
                else:
                    assert fieldstr.startswith('array(')
                    prefix = "array('X', "
                    suffix = ')'
                    fieldstr = fieldstr[len(prefix):-len(suffix)]
            args.append(s[1:] + '=' + fieldstr)
        return '%s(%s)' % ('.'.join(typename), ', '.join(args))

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        if self.message != other.message:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def message(self):
        """Message field 'message'."""
        return self._message

    @message.setter
    def message(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'message' field must be of type 'str'"
        self._message = value


class Metaclass_Action(type):
    """Metaclass of service 'Action'."""

    _TYPE_SUPPORT = None

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('communication_interface')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'communication_interface.srv.Action')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._TYPE_SUPPORT = module.type_support_srv__srv__action

            from communication_interface.srv import _action
            if _action.Metaclass_Action_Request._TYPE_SUPPORT is None:
                _action.Metaclass_Action_Request.__import_type_support__()
            if _action.Metaclass_Action_Response._TYPE_SUPPORT is None:
                _action.Metaclass_Action_Response.__import_type_support__()


class Action(metaclass=Metaclass_Action):
    from communication_interface.srv._action import Action_Request as Request
    from communication_interface.srv._action import Action_Response as Response

    def __init__(self):
        raise NotImplementedError('Service classes can not be instantiated')
