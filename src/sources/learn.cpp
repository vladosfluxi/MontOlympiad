#include "../headers/learn.h"
#include <iostream>

static void pause() {
    std::cout << "\nPress Enter to continue...";
    std::cin.ignore(1000, '\n');
}

// ─────────────────────────────────────────────
//  TOPIC 1: What is an inequality?
// ─────────────────────────────────────────────
static void topic_what_is() {
    std::cout << "\n========== WHAT IS AN INEQUALITY? ==========\n";
    std::cout << R"(
An inequality compares two expressions using one of these symbols:

  >   greater than          e.g.  5 > 3
  <   less than             e.g.  2 < 7
  >=  greater than or equal e.g.  x >= 4
  <=  less than or equal    e.g.  x <= -1
  !=  not equal to          e.g.  x != 0

Unlike an equation (=), an inequality usually has a RANGE of solutions,
not just a single value.

Example:
  x > 3   means x can be 4, 5, 100, 3.1, ... (anything bigger than 3)
  x <= 2  means x can be 2, 1, 0, -5, ... (2 or anything smaller)
)";
    pause();
}

// ─────────────────────────────────────────────
//  TOPIC 2: Golden rules
// ─────────────────────────────────────────────
static void topic_rules() {
    std::cout << "\n========== GOLDEN RULES FOR INEQUALITIES ==========\n";
    std::cout << R"(
RULE 1 – Add or subtract the same number on both sides
  The inequality sign does NOT change.

  Example:  x + 3 > 7
            x + 3 - 3 > 7 - 3
            x > 4

RULE 2 – Multiply or divide by a POSITIVE number
  The inequality sign does NOT change.

  Example:  2x < 10
            2x / 2 < 10 / 2
            x < 5

RULE 3 – Multiply or divide by a NEGATIVE number  *** FLIP THE SIGN ***
  When you multiply or divide both sides by a negative number
  the inequality sign REVERSES.

  Example:  -3x > 12
            -3x / (-3) < 12 / (-3)   <-- sign flipped from > to <
            x < -4

  Why? Think of it on a number line:
    4 > 2  is true.
    Multiply both sides by -1: -4 < -2  (now -4 is to the LEFT of -2).
    The order reversed, so the sign must flip.

RULE 4 – Moving a term to the other side
  Same as equations: move it and change its sign.

  Example:  x + 5 >= 2x - 1
            5 + 1 >= 2x - x
            6 >= x   which is the same as   x <= 6
)";
    pause();
}

// ─────────────────────────────────────────────
//  TOPIC 3: How to solve step by step
// ─────────────────────────────────────────────
static void topic_how_to_solve() {
    std::cout << "\n========== HOW TO SOLVE AN INEQUALITY ==========\n";
    std::cout << R"(
General steps (same as solving an equation, but watch the sign!):

  1. Simplify each side (expand brackets, collect like terms).
  2. Move variable terms to one side, constants to the other.
  3. Divide (or multiply) to isolate the variable.
     --> If you divide/multiply by a negative, FLIP the sign.
  4. Write the solution (e.g. x > 2) or on a number line.

─────────────────────────────────────────
EXAMPLE A  (simple)
  Solve:  3x - 4 < 11

  Step 1: 3x - 4 + 4 < 11 + 4
          3x < 15
  Step 2: 3x / 3 < 15 / 3
          x < 5

  Solution: x < 5
─────────────────────────────────────────
EXAMPLE B  (negative coefficient)
  Solve:  -2x + 1 >= 7

  Step 1: -2x >= 7 - 1
          -2x >= 6
  Step 2: divide by -2 --> FLIP the sign
          x <= -3

  Solution: x <= -3
─────────────────────────────────────────
EXAMPLE C  (variables on both sides)
  Solve:  4x + 3 > x - 6

  Step 1: 4x - x > -6 - 3
          3x > -9
  Step 2: x > -3

  Solution: x > -3
─────────────────────────────────────────
EXAMPLE D  (not-equal)
  Solve:  2x + 4 != 10

  Step 1: 2x != 6
  Step 2: x != 3

  Solution: x can be any number except 3
)";
    pause();
}

// ─────────────────────────────────────────────
//  TOPIC 4: Number line & interval notation
// ─────────────────────────────────────────────
static void topic_number_line() {
    std::cout << "\n========== NUMBER LINE & NOTATION ==========\n";
    std::cout << R"(
On a number line:
  o  (open circle)   = the endpoint is NOT included  (strict: > or <)
  *  (filled circle) = the endpoint IS included      (non-strict: >= or <=)

  x > 2    -----|--o===========>
                   2

  x <= 5   <==========*-------->
                       5

  x != 3   <==========o---o====>
                       3

Interval notation (you may see this in textbooks):
  x > 2     -->  (2, +inf)
  x <= 5    -->  (-inf, 5]
  x >= 1 and x < 4  -->  [1, 4)

Square bracket [ ] means the endpoint is included.
Round bracket ( ) means the endpoint is NOT included.
)";
    pause();
}

// ─────────────────────────────────────────────
//  TOPIC 5: Fractions in inequalities
// ─────────────────────────────────────────────
static void topic_fractions() {
    std::cout << "\n========== INEQUALITIES WITH FRACTIONS ==========\n";
    std::cout << R"(
When an inequality contains fractions, multiply both sides by the
Least Common Multiple (LCM) of all denominators to clear them.

IMPORTANT: the LCM of denominators is always a POSITIVE number,
so the inequality sign does NOT flip from this step alone.

─────────────────────────────────────────
EXAMPLE A  (one fraction per side)
  Solve:  (2x + 1) / 3  >  (x - 1) / 2

  LCM(3, 2) = 6. Multiply both sides by 6:

    6 * (2x + 1) / 3  >  6 * (x - 1) / 2
    2(2x + 1)  >  3(x - 1)
    4x + 2  >  3x - 3
    4x - 3x  >  -3 - 2
    x  >  -5

  Solution: x > -5  i.e.  (-5, +inf)

─────────────────────────────────────────
EXAMPLE B  (fraction on one side, integer on the other + negative division)
  Solve:  (x + 2) / 4  -  x / 3  <=  1

  LCM(4, 3) = 12. Multiply every term by 12:

    12 * (x + 2) / 4  -  12 * x / 3  <=  12 * 1
    3(x + 2)  -  4x  <=  12
    3x + 6  -  4x  <=  12
    -x + 6  <=  12
    -x  <=  6
    divide by -1 --> FLIP the sign
    x  >=  -6

  Solution: x >= -6  i.e.  [-6, +inf)

─────────────────────────────────────────
EXAMPLE C  (three fractions, trickier)
  Solve:  (3x - 1) / 6  -  (x + 2) / 4  >=  (x - 3) / 3

  LCM(6, 4, 3) = 12. Multiply every term by 12:

    2(3x - 1)  -  3(x + 2)  >=  4(x - 3)
    6x - 2  -  3x - 6  >=  4x - 12
    3x - 8  >=  4x - 12
    -8 + 12  >=  4x - 3x
    4  >=  x   which is the same as   x  <=  4

  Solution: x <= 4  i.e.  (-inf, 4]
)";
    pause();
}

// ─────────────────────────────────────────────
//  TOPIC 6: Polynomial inequalities (sign chart)
// ─────────────────────────────────────────────
static void topic_polynomial() {
    std::cout << "\n========== POLYNOMIAL INEQUALITIES ==========\n";
    std::cout << R"(
When an inequality contains x^2, x^3, etc., you cannot just divide
both sides to isolate x. Instead:

  1. Move everything to one side so the other side is 0.
  2. Factor the expression completely.
  3. Find the roots (where each factor = 0).
  4. Use a sign chart to check the sign of the product in each interval.
  5. Select the intervals that satisfy the inequality.

─────────────────────────────────────────
EXAMPLE A  (quadratic)
  Solve:  x^2 - 5x + 6  >  0

  Step 1: already 0 on the right.
  Step 2: factor  -->  (x - 2)(x - 3) > 0
  Step 3: roots are x = 2 and x = 3.
  Step 4: sign chart (three intervals):

    Interval     | (x-2) | (x-3) | product
    x < 2        |   -   |   -   |   +     ✓
    2 < x < 3    |   +   |   -   |   -     ✗
    x > 3        |   +   |   +   |   +     ✓

    At x=2 and x=3 the product is 0, which is NOT > 0, so exclude them.

  Solution: x < 2  or  x > 3  i.e.  (-inf, 2) U (3, +inf)

─────────────────────────────────────────
EXAMPLE B  (your example – cubic via factoring)
  Solve:  2(x + 3) + x(x^2 - 9)  >=  0

  Step 1: expand and simplify.
    2(x + 3) + x(x - 3)(x + 3)   [since x^2-9 = (x-3)(x+3)]
    Factor out (x + 3):
    (x + 3) [ 2 + x(x - 3) ]
    (x + 3) (x^2 - 3x + 2)
    (x + 3) (x - 1)(x - 2)

  Step 2: roots are x = -3, x = 1, x = 2.
  Step 3: sign chart (four intervals):

    Interval        | (x+3) | (x-1) | (x-2) | product
    x < -3          |   -   |   -   |   -   |   -     ✗
    -3 < x < 1      |   +   |   -   |   -   |   +     ✓
    1 < x < 2       |   +   |   +   |   -   |   -     ✗
    x > 2           |   +   |   +   |   +   |   +     ✓

    At x=-3, 1, 2 the product is 0, which satisfies >= 0.  Include them.

  Solution: x in [-3, 1] U [2, +inf)

─────────────────────────────────────────
EXAMPLE C  (quadratic <= 0, a different shape)
  Solve:  -x^2 + 4x - 3  <=  0

  Step 1: multiply both sides by -1 --> FLIP the sign
    x^2 - 4x + 3  >=  0
  Step 2: factor  -->  (x - 1)(x - 3) >= 0
  Step 3: roots x = 1 and x = 3.
  Step 4: sign chart:

    Interval     | (x-1) | (x-3) | product
    x < 1        |   -   |   -   |   +     ✓
    1 < x < 3    |   +   |   -   |   -     ✗
    x > 3        |   +   |   +   |   +     ✓

    Endpoints x=1 and x=3 give product=0 >= 0, so include them.

  Solution: x <= 1  or  x >= 3  i.e.  (-inf, 1] U [3, +inf)
)";
    pause();
}

// ─────────────────────────────────────────────
//  SUB-MENU
// ─────────────────────────────────────────────
void show_learning_content() {
    while (true) {
        std::cout << "\n===== LEARNING CONTENT: INEQUALITIES =====\n";
        std::cout << "1. What is an inequality?\n";
        std::cout << "2. Golden rules (including the flip rule)\n";
        std::cout << "3. How to solve – step by step with examples\n";
        std::cout << "4. Number line & interval notation\n";
        std::cout << "5. Inequalities with fractions\n";
        std::cout << "6. Polynomial inequalities (sign chart method)\n";
        std::cout << "7. Back to main menu\n";
        std::cout << "Choose a topic (1-7): ";

        char ch;
        if (!(std::cin >> ch)) {
            std::cin.clear();
            std::cin.ignore(1000, '\n');
            continue;
        }
        std::cin.ignore(1000, '\n');

        switch (ch) {
        case '1': topic_what_is();       break;
        case '2': topic_rules();         break;
        case '3': topic_how_to_solve();  break;
        case '4': topic_number_line();   break;
        case '5': topic_fractions();     break;
        case '6': topic_polynomial();    break;
        case '7': return;
        default:  std::cout << "Invalid choice.\n"; break;
        }
    }
}
