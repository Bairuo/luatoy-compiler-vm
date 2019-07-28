function f()
  local a, b = 1, 2; print(a, b)
  local a, b = 3, 4; print(a, b)
  do
    print(a, b)    
    local a, b = 5, 6; print(a, b)
  end
  print(a, b)  
end

f()