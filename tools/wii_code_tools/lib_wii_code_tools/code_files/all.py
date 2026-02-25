
from . import CodeFile
from . import alf
from . import dol
from . import rel


libs = [dol, rel, alf]
file_types = [lib.file_type for lib in libs]
section_types = [lib.section_type for lib in libs]
extension_to_lib = {lib.extension: lib for lib in libs}


def load_by_extension(data: bytes, extension: str) -> CodeFile:
    """
    Given file data and a file extension (e.g. '.dol'), try to load and
    return the appropriate CodeFile subclass. If there isn't one, return
    None.
    """
    module = extension_to_lib.get(extension)
    if module is not None:
        return module.file_type(data)
    else:
        return None
