import random
i = 0;
while i < 1000000:
	a = random.randint(0, 32767)
	b = random.randint(0, 32767)
	c = a+b
	i = i + 1
print "Added 1,000,000 random integers using Python"