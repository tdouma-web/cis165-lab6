# CIS-165 Lab 6

**Name:** Theo Douma  
**Section:** CIS-165-W099

## Initial Plans

**bmi.cpp:** I will ask the user for their weight in pounds and height in inches, and store both in `double` variables (`weight` and `height`). First, I will validate that both numbers are greater than zero; if either is zero or negative, I will print an error message and stop the program. If they are valid, I will calculate the BMI using `bmi = weight * 703.0 / (height * height)` and store it in a `double` variable (`bmi`). Next, I will use `if / else if / else` statements on the unrounded `bmi` to check if it is under 18.5 (Underweight), between 18.5 and 25.0 inclusive (Optimal weight), or above 25.0 (Overweight). Finally, I will print the BMI formatted to two decimal places using `fixed` and `setprecision(2)` along with its category. I will test normal ranges, exact boundaries, and zero/negative inputs.

**color_mixer.cpp:** I will define a constant `const int COLOR_SIZE = 20;` and create two `char` arrays (`first_color` and `second_color`). I will read two primary color names from the user using `cin >> setw(COLOR_SIZE)` to prevent buffer overflow. Using `strcmp` from `<cstring>`, I will first validate that both inputs are either `"red"`, `"blue"`, or `"yellow"`. If either input is invalid, I will print an error message. If both are valid, I will check if the two strings match each other and print that single color if they do. Otherwise, I will check the pairs in either order (`red` + `blue` = `purple`, `red` + `yellow` = `orange`, `blue` + `yellow` = `green`), store the mixed color result, and print it. I will test all color combinations in both orders, matching colors, and invalid color names.

## Run Instructions

**Method 1: OnlineGDB (Used for writing and testing)**
1. Go to onlinegdb.com and select **C++17** as the language.
2. Open one program at a time (`bmi.cpp` or `color_mixer.cpp`), paste the code into the editor, and click **Run** at the top.

## Test Table

| Program/test | Inputs | Expected result | Actual result | Match or correction |
| :--- | :--- | :--- | :--- | :--- |
| BMI (assigned) | 100, 70 | 14.35 — Underweight | BMI: 14.35 — Underweight | Match |
| BMI (assigned) | 150, 70 | 21.52 — Optimal weight | BMI: 21.52 — Optimal weight | Match |
| BMI (assigned) | 200, 70 | 28.69 — Overweight | BMI: 28.69 — Overweight | Match |
| BMI (assigned) | 150, 0 | Error: weight and height must be positive. | Error: weight and height must be positive. | Match |
| BMI (assigned) | -150, 70 | Error: weight and height must be positive. | Error: weight and height must be positive. | Match |
| BMI (extra test) | 128.92857, 70 | 18.50 — Optimal weight | BMI: 18.50 — Optimal weight | Match (Checks the 18.5 lower boundary of Optimal weight) |
| Color Mixer (assigned) | red, blue | purple | purple | Match |
| Color Mixer (assigned) | red, yellow | orange | orange | Match |
| Color Mixer (assigned) | blue, yellow | green | green | Match |
| Color Mixer (assigned) | blue, red | purple | purple | Match |
| Color Mixer (assigned) | red, red | red | red | Match |
| Color Mixer (assigned) | orange, blue | Error: enter red, blue, or yellow. | Error: enter red, blue, or yellow. | Match |
| Color Mixer (assigned) | red, orange | Error: enter red, blue, or yellow. | Error: enter red, blue, or yellow. | Match |
| Color Mixer (extra test) | yellow, blue | green | green | Match (Checks reversed input order for blue and yellow) |

**Boundary Note:** A BMI of exactly 18.5 or 25.0 belongs in the **Optimal weight** category because the classification rules state "18.5 through 25.0, including both endpoints." Using inclusive operators (`<= 25.0` after checking `< 18.5`) guarantees that both 18.5 and 25.0 fall into the Optimal weight.

## Explanations

1. **BMI formula and `height * height`:** The formula multiplies weight in pounds by `703.0` to convert from imperial units (pounds and inches) to the standard metric BMI scale, then divides by height squared. `height * height` is required because the `^` operator in C++ performs a bitwise XOR operation, not exponentiation.
2. **Handling 18.5 and 25.0 boundaries:** My code checks `if (bmi < 18.5)` first, then `else if (bmi <= 25.0)`, and finally `else`. Because `18.5` is not less than `18.5`, it moves to the `else if` branch where `<= 25.0` catches both `18.5` and `25.0`. The order matters because checking `< 18.5` first lets the second condition simply check `<= 25.0` without gaps or overlapping ranges.
3. **Checking weight and height first:** Validating that both inputs are positive before calculating prevents dividing by zero (if height is `0`) and prevents calculating a meaningless negative or zero BMI.
4. **Unrounded classification vs. rounded display:** Classifying the unrounded `bmi` ensures true mathematical accuracy (for example, a BMI of `25.004` is truly Overweight, even though it rounds to `25.00` on screen). Using `fixed` and `setprecision(2)` only formats how `cout` prints the number without changing the value stored in the variable.
5. **`strcmp` vs. `==` for char arrays:** `strcmp` returns `0` when two character strings have identical characters. Using `==` on two `char` arrays does not compare the text inside them; instead, it compares their memory addresses, which will always be different for two separate variables.
6. **Order-independent mixtures and identical colors:** For identical primary colors, I check if `strcmp(first_color, second_color) == 0` and print `first_color`. For mixtures, I use `||` (OR) with `&&` (AND) to check both directions at once—for example, `(strcmp(first_color, "red") == 0 && strcmp(second_color, "blue") == 0) || (strcmp(first_color, "blue") == 0 && strcmp(second_color, "red") == 0)`.
7. **Checking for invalid colors in either position:** Before mixing, I check that `first_color` matches `"red"`, `"blue"`, or `"yellow"`, AND that `second_color` matches `"red"`, `"blue"`, or `"yellow"`. If either check fails, the program immediately outputs an error message instead of attempting to mix them.
8. **Named constants and result variables:** Named constants like `COLOR_SIZE` avoid magic numbers and make it easy to update array limits in one place. Storing calculations in result variables like `bmi` before printing keeps `cout` statements clean, makes debugging easier, and lets the program reuse the value for both classification and display.
