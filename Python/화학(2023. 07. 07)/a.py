from periodictable import elements

def calculate_molar_mass(formula):
    elements_data = {}
    element_count = {}

    # 화학식을 요소와 개수로 분해하여 딕셔너리에 저장합니다.
    i = 0
    while i < len(formula):
        if formula[i].isupper():
            element = formula[i]
            i += 1
            while i < len(formula) and formula[i].islower():
                element += formula[i]
                i += 1
            if i < len(formula) and formula[i].isdigit():
                count = ""
                while i < len(formula) and formula[i].isdigit():
                    count += formula[i]
                    i += 1
                element_count[element] = int(count)
            else:
                element_count[element] = 1
        elif formula[i] == "(":
            i += 1
            parentheses_formula = ""
            open_parentheses = 1
            while i < len(formula) and open_parentheses > 0:
                if formula[i] == "(":
                    open_parentheses += 1
                elif formula[i] == ")":
                    open_parentheses -= 1
                parentheses_formula += formula[i]
                i += 1
            parentheses_count = ""
            while i < len(formula) and formula[i].isdigit():
                parentheses_count += formula[i]
                i += 1
            sub_formula = calculate_molar_mass(parentheses_formula)
            for element, count in sub_formula.items():
                if element in element_count:
                    element_count[element] += count * int(parentheses_count)
                else:
                    element_count[element] = count * int(parentheses_count)

    # 요소의 화학식량을 계산하여 딕셔너리에 저장합니다.
    for element, count in element_count.items():
        atomic_mass = elements.symbol(element).mass
        element_mass = f"{atomic_mass} * {count}"
        elements_data[element] = element_mass

    return elements_data

# 화학식을 입력받고 화학식량을 계산합니다.
chemical_formula = input("화학식을 입력하세요: ")
molar_mass = calculate_molar_mass(chemical_formula)

# 계산된 화학식량과 분자의 화학식량을 출력합니다.
print("화학식량:")
for element, mass in molar_mass.items():
    print(element, ":", mass)

# 분자의 화학식량을 계산합니다.
molecular_mass = sum(float(mass.split(' * ')[0]) * float(mass.split(' * ')[1]) for mass in molar_mass.values())

print("분자의 화학식량:", molecular_mass)
