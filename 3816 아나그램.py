for ro in range(int(input())):
    s1, s2 = input().split()

    word = {}
    for letter in s1:
        if word.get(letter) != None:
            word[letter] += 1
        else:
            word[letter] = 1
    
    temp_word = {}
    length = len(s1)

    for idx in range(length):
        if temp_word.get(s2[idx]) != None:
            temp_word[s2[idx]] += 1
        else:
            temp_word[s2[idx]] = 1
    cnt = 0
    if temp_word == word:
        cnt += 1
    
    for idx in range(length, len(s2)):
        temp_word[s2[idx - length]] -= 1
        if temp_word[s2[idx - length]] == 0:
            del temp_word[s2[idx - length]]
        
        if temp_word.get(s2[idx]) != None:
            temp_word[s2[idx]] += 1
        else:
            temp_word[s2[idx]] = 1

        if temp_word == word:
            cnt += 1

    print('#%d %d' %(ro + 1, cnt))

