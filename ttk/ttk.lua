function calculate_ttk(damage, health, rpm)
    local shots_to_kill = math.ceil(health / damage)
  
    local rps = rpm / 60
  
    local ttk = (shots_to_kill - 1) / rps
  
    return math.max(ttk, 0)
end

local new = {
    {name = "ASS", damage = 22, rpm = 530},
    {name = "BAN", damage = 18, rpm = 630},
    {name = "TAC", damage = 26, rpm = 430},
    {name = "SNI", damage = 70, rpm = 120},
    {name = "PIS", damage = 40, rpm = 400},
    {name = "REV", damage = 50, rpm = 400}
}

print("enter hp")
local health = io.read("*n")

for i, weapon in ipairs(new) do
    local ttk = calculate_ttk(weapon.damage, health, weapon.rpm)
    print(string.format("%s DMG: %d RPM: %d TTK: %.2f", 
        weapon.name, weapon.damage, weapon.rpm, ttk))
end
print("")
for i, weapon in ipairs(new) do
    local hsdmg = math.ceil(weapon.damage * 1.72)
    local ttk = calculate_ttk(hsdmg, health, weapon.rpm)
    print(string.format("%s HSDMG: %d RPM: %d TTK: %.2f", 
        weapon.name, hsdmg, weapon.rpm, ttk))
end
