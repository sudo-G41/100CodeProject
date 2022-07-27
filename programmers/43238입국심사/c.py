def solution(n, times):
    answer = 0
    min_time = 0
    max_time = max(times)*n
    while(max_time!=min_time+1):
        mid = (min_time+max_time)//2
        wait = sum([mid//v for v in times])
        if(wait<n):
            min_time = mid
        else:
            max_time = mid
    return max_time