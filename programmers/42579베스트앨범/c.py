def solution(genres, plays) :
    answer = []
    counting_paly = {}
    music = {}
    for idx in range(len(genres)):
        if genres[idx] in counting_paly:
            counting_paly[genres[idx]] += plays[idx]
            if plays[idx] in music[genres[idx]]:
                music[genres[idx]][plays[idx]].append(idx)
            else:
                music[genres[idx]][plays[idx]] = [idx]
        else:
            counting_paly[genres[idx]] = plays[idx]
            music[genres[idx]] = {plays[idx]:[idx]}
    
    counting_paly = sorted(counting_paly.items(), key=lambda x:x[1], reverse=True)
    for k, v in counting_paly:
        tmp = sorted(music[k].items(), key=lambda x:x[0])
        answer.append(tmp[-1][1].pop(0))
        if(tmp[-1][1]):
            answer.append(tmp[-1][1].pop(0))
        elif(len(tmp)>1):
            answer.append(tmp[-2][1].pop(0))

    return answer