import enum

class ErrorVolume(enum.Enum):
    """
    How loudly to complain about something
    """
    ERROR = 'error'
    WARNING = 'warning'
    SILENT = 'silent'

    @classmethod
    def default(cls):
        return cls.WARNING
