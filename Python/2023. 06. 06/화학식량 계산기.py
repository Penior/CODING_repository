import periodictable
from periodictable import H,N,C,O
H_mass = H.mass
C_mass = C.mass
O_mass = O.mass
N_mass = N.mass

print("화학식을 입력하십시오")
chemical = input()
stack = []
atom = {'H':H_mass, 'C':C_mass, 'O':O_mass, 'N':N_mass}
for c in chemical:
  if c=='(':
    stack.append(c)
  elif c=='H' or c=='C' or c=='O' or c=='N':
    stack.append(atom[c])
  elif c==')':
    temp = 0
    while True:
      if stack[-1] == '(':
        stack.pop()
        stack.append(temp)
        break
      else:
        temp+=stack.pop()
  else:
    stack.append(stack.pop()*int(c))
print(sum(stack))