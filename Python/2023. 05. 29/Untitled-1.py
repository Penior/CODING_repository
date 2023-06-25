import string
import random

STR = "Science"
score = 0
arrayA = [[]]
ListB = [[]]

arrayA.pop()
ListB.pop()
for i in range(100):
    letters_set = string.ascii_letters
    random_list = random.sample(letters_set,7)
    result = ''.join(random_list)

    if result.find('S') > -1 :
        score = 1
        if result[0] == 'S' :
            score += 2
    if result.find('c') > -1 :
        score += 1
        if result[1] == 'c' :
            score += 2
        if result[5] == 'c' :
            score += 2
    if result.find('i') > -1 :
        score += 1
        if result[2] == 'i' :
            score += 2
    if result.find('e') > -1 :
        score += 1
        if result[3] == 'e' :
            score += 2
        if result[6] == 'e' :
            score += 2
    if result.find('n') > -1 :
        score += 1
        if result[4] == 'n' :
                score += 2
    score = score * abs(7  - abs(7 - len(result)))
    arrayA.append([result, score])
    score = 0
arrayA.sort(key=lambda x:-x[1])
listB = arrayA[:10]
print(listB)

for i in range(300):
    arrayA = listB
    for i in range(15):
        ran1 = random.randint(0,9)
        ran2 = random.randint(0,6)
        ran3 = random.randint(0,9)
        ran4 = random.randint(0,2)
        ran6 = random.randint(0,6)
        ran7 = random.randint(0,6)
        ran8 = random.randint(0,6)
        resultA = list(listB[ran1][0])
        resultA[ran2] = ''.join(random.sample(letters_set,1))
        resultA[ran6] = ''.join(random.sample(letters_set,1))
        resultA[ran7] = ''.join(random.sample(letters_set,1))
        resultB = list(listB[ran3][0])
        if ran4 == 2 :
            resultA[ran2] = resultB[ran2]
        result = ''.join(resultA)
        if result.find('S') > -1 :
            score = 1
            if result[0] == 'S' :
                score += 2
        if result.find('c') > -1 :
            score += 1
            if result[1] == 'c' :
                score += 2
            if result[5] == 'c' :
                score += 2
        if result.find('i') > -1 :
            score += 1
            if result[2] == 'i' :
                score += 2
        if result.find('e') > -1 :
            score += 1
            if result[3] == 'e' :
                score += 2
            if result[6] == 'e' :
                score += 2
        if result.find('n') > -1 :
            score += 1
            if result[4] == 'n' :
                    score += 2
        score = score * abs(7  - abs(7 - len(result)))
        arrayA.append([result, score])
        score = 0
    arrayA.sort(key=lambda x:-x[1])
    listB = arrayA[:10]
    print(listB)
