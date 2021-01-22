trans = input()
rec = input()
rlis = [0]*4
if(4 <= len(trans) <= 11):
    new_str = trans[-len(trans):-4]+"0"+trans[3:6]+"0"+trans[6]+"00"
    rlis[-1] = int(new_str[-11]) ^ int(new_str[-9]
                                       ) ^ int(new_str[-7]) ^ int(new_str[-5]) ^ int(new_str[-3])
    rlis[-2] = int(new_str[-3]) ^ int(new_str[-6]) ^ int(new_str[-7]
                                                         ) ^ int(new_str[-10]) ^ int(new_str[-11])
    rlis[-3] = int(new_str[-5]) ^ int(new_str[-6]) ^ int(new_str[-7])
    rlis[-4] = int(new_str[-9]) ^ int(new_str[-10]) ^ int(new_str[-11])

    print(rlis)
    print(new_str)
    print(len(new_str))

# ---------------------------------------------
rlis2 = [0]*4
if(8 <= len(rec) <= 15):
    rlis2[-1] = int(rec[-11]) ^ int(rec[-9]) ^ int(rec[-7]
                                                   ) ^ int(rec[-5]) ^ int(rec[-3]) ^ int(rec[-1])
    rlis2[-2] = int(rec[-3]) ^ int(rec[-6]) ^ int(rec[-7]
                                                  ) ^ int(rec[-10]) ^ int(rec[-11]) ^ int(rec[-2])
    rlis2[-3] = int(rec[-5]) ^ int(rec[-6]) ^ int(rec[-7]) ^ int(rec[-4])
    rlis2[-4] = int(rec[-9]) ^ int(rec[-10]) ^ int(rec[-11]) ^ int(rec[-8])

    err = int("".join([str(x) for x in rlis2]), 2)
    print(err)
