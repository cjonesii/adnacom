def calc_total(*args):
	total = 0
	for num in args:
		total += num
	return total

def calc_ave(*args):
	total = calc_total(*args)
	return total/len(args)

numbers = [1,2,3,4,5]
result1 = calc_total(*numbers)
result2 = calc_ave(*numbers)

print(result1, result2)