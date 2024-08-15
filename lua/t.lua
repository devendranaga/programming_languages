local name = "constantine"
local a = 10
local b = 2

function fact(n)
	if n == 0 then
		return 1
	else
		return n * fact(n - 1)
	end
end

print("a + b = ".. a+b)
print("a - b = ".. a-b)
print("a / b = ".. a/b)
print("a * b = ".. a*b)
print("name is ".. name)

local val = io.read("*number")

print("val is ".. fact(val))
