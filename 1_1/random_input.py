import random
c=""
for j in range(1618):	
	s=""
	for i in range(100):
		s+=random.choice(["A","T","C","G"])
	#print(s)
	c+=s
	c+="   "
print c

