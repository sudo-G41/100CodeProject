def solution(phone_book):
    phone_book.sort()
    tree = {"end":False}
    for num in phone_book:
        tmp = tree
        for c in num:
            if(c not in tmp):
                tmp[c]={"end":False}
            if(tmp["end"]):
                return False
            tmp = tmp[c]
        if(len(tmp)!=1):
            return False
        tmp["end"] = True
    return True