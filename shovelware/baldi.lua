local answer = {}
local op = {"+", "-", "*", "%"}

local calc = function(t1, t2, o)
    return  o == "+" and t1 + t2 or 
            o == "-" and t1 - t2 or 
            o == "*" and t1 * t2 or 
            o == "%" and t1 % t2
end

while true do 
    local t1, t2, o = math.random(1, 9), math.random(1, 9), op[math.random(1, 4)]
    local correct = calc(t1, t2, o) 
    
    print(("Problem #%d (%d %s %d = ?)"):format(#answer + 1, t1, o, t2))
    
    local user = io.read("*n")
    
    local act = user and function()
        answer[#answer + 1] = user == correct
    
        print((answer[#answer] and 
        "Great job! (%d %s %d = %d)\n" or 
        ">:( (%d %s %d = %d) Your answer (%d) is wrong\n"
        ):format(t1, o, t2, correct, user))
    end or function() end
    
    act()
end
