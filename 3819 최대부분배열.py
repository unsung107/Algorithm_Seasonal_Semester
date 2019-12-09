for ro in range(int(input())):
    N = int(input())

    max_minus = -1001
    max_result = -1001
    temp_sum = 0
    for i in range(N):
        number = int(input())
        if number < 0:
            if max_minus < number:
                max_minus = number
        if temp_sum <= temp_sum + number:
            temp_sum += number
            if temp_sum > max_result:
                max_result = temp_sum

        else:
            temp_sum = 0
    
    if max_result == -1001:
        max_result = max_minus
    print('#%d %d' %(ro + 1, max_result))