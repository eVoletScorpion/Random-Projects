local health = 200

function calculate_ttk(damage, health, rpm)
    local shots_to_kill = math.ceil(health / damage)
  
    local rps = rpm / 60
  
    local ttk = (shots_to_kill - 1) / rps
  
    return math.max(ttk, 0)
end

function calculate_dps(damage, rpm)
    return damage * rpm / 60
end

function split(inputstr, seperator)
   if seperator == nil then
      seperator = "%s"
   end
    
   local words = {}
   for str in string.gmatch(inputstr, "([^"..seperator.."]+)") do
      table.insert(words, str)
   end
    
   return words
end

local weapons = {
    {name = "M4", damage = 22, rpm = 530},
    {name = "TOMMY", damage = 18, rpm = 630},
    {name = "STEN", damage = 26, rpm = 430},
    {name = "SNIPER", damage = 70, rpm = 120},
    {name = "PISTOL", damage = 40, rpm = 400},
    {name = "REVOLVER", damage = 50, rpm = 400}
}

function add_item(i, ii, iii)
    table.insert(weapons, {name = string.upper(i), damage = ii, rpm = iii})
end

print("Commands:\nadd [name] [damage] [rpm],\nttk [name] [level],\nhealth [number],\nlist,\nquit\n")
while true do
    local input = io.read("*l")
    
    local words = split(input)
    local command = string.lower(words[1])

    if command == "ttk" then -- the variable names in this statement are so bad
        local inputWeapon = words[2]
        if inputWeapon then
            inputWeapon = string.upper(words[2])
        else
            print("Missing weapon argument\n")
            goto continue
          --  continue WHY DOES LUA NOT HAVE CONTINUE DAWG
        end
        
        local level = words[3]
        if level then
            level = tonumber(words[3])
        else
            print("Missing level argument\n")
            goto continue
        end
        
        local weapon
        local result = 0
    
        for _, weaponIndex in ipairs(weapons) do
            local weaponName = weaponIndex.name
            if weaponName == inputWeapon then 
                weapon = weaponIndex
                break
            end
        end
        
        if not weapon then
            print("Weapon not found\n")
            goto continue
        end
        
        for i = 1, level do
            result = 1.00 + 0.05 * i - 0.05
        end
    
        local damage = weapon.damage * result
    
        local ttk = calculate_ttk(damage, health, weapon.rpm)
        print(string.format("%s\nDMG: %.2f RPM: %.2f\nTTK: %.2f\nLVL: %d HP: %d\n",
        weapon.name, damage, weapon.rpm, ttk, level, health))
        ::continue::
    elseif command == "dps" then
        print("ill do it later smh my head")
    elseif command == "health" then
        health = tonumber(words[2])
        if health and type(health) == "number" then
            print(string.format("health is now %d\n", health))
        else
            print("Missing health argument or argument isn't a number\n")
            health = 200
        end
    elseif command == "list" then
        for i, weapon in ipairs(weapons) do
            print(string.format("%s DMG: %d RPM: %d", 
            weapon.name, weapon.damage, weapon.rpm))
        end
        print("")
    elseif command == "add" then
        local name, dmg, rpm = words[2], tonumber(words[3]), tonumber(words[4])
        if name and dmg and rpm then
            add_item(name, dmg, rpm)
        else
            print("Missing argument or incorrect data type\n")
        end
    elseif command == "exit" or command == "quit" or command == "q" then
        print("\ncya\n")
        break
    else
        print("Unknown command, try again")
    end
end
