def delete_vowels(s):
    vowels = "aeiouAEIOU"
    return ''.join(ch for ch in s if ch not in vowels)

print(delete_vowels("Hello Worl
d"))
