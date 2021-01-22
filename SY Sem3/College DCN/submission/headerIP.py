
hex_string = input()
binary_string = ""
for i in hex_string:
    binary_string+=format(int(i,16),"04b")
padding = binary_string[160:]
print(binary_string)
binary_string = binary_string[:160]

print("Source Port : ",int(binary_string[:16],2))
print("Destination Port : ",int(binary_string[16:32],2))
print("Sequence Number  : ",int(binary_string[32:64],2))
print("Acknowledgment Number  : ",int(binary_string[64:96],2))
print("HLEN : ",int(binary_string[96:100],2))
print("Reserved Bits : ",int(binary_string[100:106],2))
urg = int(binary_string[106],2)
print("Urgent Flag : ",urg)
print("Ack Flag : ",int(binary_string[107],2))
print("Psh Flag : ",int(binary_string[108],2))
print("Rst Flag : ",int(binary_string[109],2))
print("Syn Flag : ",int(binary_string[110],2))
print("Fin Flag : ",int(binary_string[111],2))
print("Window size : ",int(binary_string[111:128],2))
print("Checksum : ",int(binary_string[128:144],2))
if(urg):
    print("Urgent Pointer : ",int(binary_string[144:160],2))

print("Padding : ",padding)


