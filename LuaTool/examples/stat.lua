local a = { [0] = 1, ["x"] = 2, y = 3}

local z = 1.5
local str = "string var"
local x, y = -1, 1

y = (x + y) * y

if x < y then
	print("x < y")
end

while x < y do
	x = x + 1
end

print("hello world")

function f(x, y)
	print(x + 1 * y)
end

f(1, 1)

print(z)
print(str)

print(a["x"])
print(a["y"])