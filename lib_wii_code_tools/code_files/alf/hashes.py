
def hash(s: str, *, seed=0x1505) -> int:
    """
    The ALF symbol table string-hashing function
    """
    state = seed
    for c in s:
        state = (33 * state) ^ ord(c)
    return state & 0xFFFFFFFF
