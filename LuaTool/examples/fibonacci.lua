function fibonacci(n)
  if n < 2 then
    return n
  else
    return fibonacci(n-1) + fibonacci(n-2)
  end
end

for i = 1, 10 do
	print(fibonacci(i))
end
