def to_lowercase(ch):
    if 'A' <= ch <= 'Z':
        return chr(ord(ch) + 32)
    return ch

print(to_lowercase('G'))
