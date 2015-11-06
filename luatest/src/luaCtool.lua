function NetRecive(ptype,msg,isPush)

    print("call cpp1 \n")

    print(ptype)
    print(" ")
    print(msg)
    print(" ")
    print(isPush)
    print(" ")

    print("call cpp2 \n")

    NetSend(10001,"lua send str test!")

end