
class CodeFileSection:
    """
    ABC for a code file section
    """
    address: int = None  # can be None for position-independent code
    size: int
    data: bytes = None
    is_executable: bool = None  # set to None if it's not explicitly stated in the code file

    def is_null(self) -> bool:
        return self.size == 0

    def is_bss(self) -> bool:
        return self.data is None


class CodeFile:
    """
    ABC for a code file (DOL, REL, ALF)
    """
    entry_point: int = None  # can be None for things like REL
    sections: list
