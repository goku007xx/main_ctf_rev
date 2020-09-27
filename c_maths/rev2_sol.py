from pwn import *
from math import *

#elf=ELF("./rev2")
#p=elf.process()
p=remote("cmaths.darkarmy.xyz",7001)

def byte2str(byte):
	return str(byte,"utf-8")

def rot11(i):
	if(i.isalpha()):
		return (chr(((ord(i) - ord('a') + 11) % 26 + ord('a'))))
	else:
		return i

def sum2(a):
	r=0
	sum3=0
	while(a>0):
		r=a%10
		sum3+=r
		a=int(a/10)
	return sum3
	
# PART1
string="3h8t1e"
var=11
output=""

for i in string:
	x=rot11(i)
	output+=x

output=output[::-1]
print(output)	# First part of flag
p.sendline(output)

#PART2
sum1=0
list1=[]
for i in range(9):
	z=(int(byte2str(p.recvline().rstrip())))
	sum1+=z
	list1.append(z)


avg=(sum1/9)

SD=0;
for i in list1:
	SD+=(i-avg)**2

SD=int(sqrt((int(SD)/9)))
p.sendline(str(SD))
print(byte2str(p.recv())) # small_chunk (2nd part of flag)

val=int(byte2str(p.recv()))

final_list=[]
for i in range(100,val):
	d=sum2(i)
	if((d%2==0) and (d%3==0)):
		final_list.append(i)

final_list.reverse()
#print(final_list)
final_value=0

for i in range(len(final_list)):
	if( i%2 != 0):
		final_value+=final_list[i]

p.sendline(str(final_value))
print(byte2str(p.recv())) # Big chunk (3rd part of flag)



