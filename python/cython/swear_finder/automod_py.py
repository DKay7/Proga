

BAD_WORDS_LIST = ["бля", "пидор", "хуй", "гандон", "пизда", "пиздец",
                        "охуенно", "ебат", "заебать", "заебало", "ебан", "еблан"]


def levenshtein_distance(first, second):
    first = first.lower()
    second = second.lower()

    len_first, len_second = len(first), len(second)

    if len_first > len_second:
        first, second = second, first
        len_first, len_second = len_second, len_first

    current_row = range(len_first + 1)
    for i in range(1, len_second + 1):
        previous_row, current_row = current_row, [i] + [0] * len_first
        for j in range(1, len_first + 1):
            add, delete, change = previous_row[j] + 1, current_row[j - 1] + 1, previous_row[j - 1]
            if first[j - 1] != second[i - 1]:
                change += 1
            current_row[j] = min(add, delete, change)

    return current_row[len_first]


LETTER_ALIASES = {
    'а': ['а', 'a', '@'],
    'б': ['б', '6', 'b'],
    'в': ['в', 'b', 'v'],
    'г': ['г', 'r', 'g'],
    'д': ['д', 'd'],
    'е': ['е', 'e'],
    'ё': ['ё', 'e'],
    'ж': ['ж', 'zh', '*'],
    'з': ['з', '3', 'z'],
    'и': ['и', 'u', 'i'],
    'й': ['й', 'u', 'i'],
    'к': ['к', 'k', 'i{', '|{'],
    'л': ['л', 'l', 'ji'],
    'м': ['м', 'm'],
    'н': ['н', 'h', 'n'],
    'о': ['о', 'o', '0'],
    'п': ['п', 'n', 'p'],
    'р': ['р', 'r', 'p'],
    'с': ['с', 'c', 's'],
    'т': ['т', 'm', 't'],
    'у': ['у', 'y', 'u'],
    'ф': ['ф', 'f'],
    'х': ['х', 'x', 'h', '}{'],
    'ц': ['ц', 'c', 'u,'],
    'ч': ['ч', 'ch'],
    'ш': ['ш', 'sh'],
    'щ': ['щ', 'sch'],
    'ь': ['ь', 'b'],
    'ы': ['ы', 'bi'],
    'ъ': ['ъ'],
    'э': ['э', 'e'],
    'ю': ['ю', 'io'],
    'я': ['я', 'ya']
}


def replace_aliases(phrase):
    phrase = phrase.lower().strip().replace(" ", "")

    for key, value in LETTER_ALIASES.items():
        for letter in value:
            for phr in phrase:
                if letter == phr:
                    phrase = phrase.replace(phr, key)

    return phrase


def contains_bad_words(phrase):
    phrase = replace_aliases(phrase)

    for word in BAD_WORDS:
        for part in range(len(phrase)):
            fragment = phrase[part: part+len(word)]
            if levenshtein_distance(fragment, word) <= len(word)*0.25:
                return True

    return False
