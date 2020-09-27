input1="!8u)05/>!#,.W/%H-G"
xor="ZUB*aVrOUsCPS;$R=Q"

newinput1=""
newinput2=""
newinput3=""
newinput4=""
for i in range(len(input1)):
	if(i%2==0):
		newinput1+=input1[i]

for i in range(len(xor)):
	if(i%2!=0):
		newinput2+=xor[i]

for i in range(len(input1)):
	if(i%2!=0):
		newinput3+=input1[i]

for i in range(len(xor)):
	if(i%2==0):
		newinput4+=xor[i]

'''print(newinput1)
print(newinput2)

print(newinput3)
print(newinput4)'''

xored=[]
k=0
for i,j in zip(newinput1,newinput2):
	xored.insert(k,chr(ord(i) ^ ord(j)))
	k+=2

l=1
for i,j in zip(newinput3,newinput4):
	xored.insert(l,chr(ord(i) ^ ord(j)))
	l+=2

stage1="".join(xored)
first_half=stage1[0:9]
second_half=stage1[9:18]

n=3
part_one=""
for i in first_half:
	part_one+=chr((ord(i) - ord('a') + n) % 26 + 97)
	n+=3

part_two=""
for i in second_half:
	part_two+=chr((ord('z')-ord(i))+ord('a'))

part_two=part_two[::-1]

b=0
final_list=[]
for i,j in zip(part_one,part_two):
	final_list.insert(b,i+j)
	b+=1

answer="".join(final_list)
print("darkCTF{"+answer+"}")

#Flag=darkCTF{answer}
