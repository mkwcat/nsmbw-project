from . import correct as lib_correct
from . import nvidia as lib_nvidia


def demangle(sym: str, *, nvidia: bool = False) -> str:
    """
    Demangle a symbol using either Nvidia's broken algorithm, or a
    correct algorithm.
    """
    if nvidia:
        return lib_nvidia.demangle(sym)
    else:
        return lib_correct.demangle(sym)
