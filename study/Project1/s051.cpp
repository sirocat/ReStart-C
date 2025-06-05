#include <stdio.h>
#include <cmath>//pi및 tan값 계산을 위해 사용

#define W_SIZE 235//캔버스 너비
#define H_SIZE 65//캔버스 높이

int car[H_SIZE][W_SIZE];//배열 크기 선언
int cnt_x, cnt_y, menu; //1부터 시작하지 않는 for문의 j, i값을 변환하기 위한 변수들
const double PI = acos(-1.0);//pi 선언 // Using acos from <math.h> (included via <cmath> or standalone)

// --- 함수 원형(Prototypes) 선언 ---
// 함수 정의보다 먼저 함수를 사용하려면 여기에 함수 원형을 선언해야 합니다.
void initializeCar();
bool tanc(int x, int y, float a, int b, int cnt_x, int cnt_y, bool direction_, int hollow); // Added hollow parameter
bool circle_c(int px, int py, int a, int b, int x, int y);
void Charinput(int x, int y, char asci);
void printCar();
void Square(int x, int y, int xinc, int yinc, char r, bool cover, int stroke, float aa, int bb, bool direction, int wp, int hp); // Added default values here or handle in definition
void Circle(int x, int y, int xinc, int yinc, char r, bool cover, int stroke, float aa, int bb, bool direction, int wp, int hp); // Added default values here or handle in definition
// --- 함수 원형 선언 끝 ---


//네모 타원 문자열 그라데이션
// @@@@@@@###$$$====***!!!;;;;:::~~~----,,,...

// 함수 정의(Definitions)는 원형 선언 뒤에 옵니다.
void initializeCar() {
    // 전체 배열을 공백으로 초기화
    for (int i = 0; i < H_SIZE; i++) {
        for (int j = 0; j < W_SIZE; j++) {
            car[i][j] = 32;
        }
    }
}

//       다른 도형 함수로부터 입력된 for문(줄여서 그냥 for문이라 하겠음)
//   x : for문의 j값 | a : 기울기(각도) | cnt_x :  for문의 j값에서 도형 x좌표를 뺀값
//   y : for문의 i값 | b : 절  편       | cnt_y :  for문의 i값에서 도형 y좌표를 뺀값
//                                   direction_ : 그래프 기준으로 도형을 잘라낼 방향(true = 좌측.false = 우측
//                                                                                   연산은 도형 내에서만 진행되기에
//                                                                                   다른 도형에 영향을 주지 않음.  )
//
bool tanc(int x, int y, float a, int b, int cnt_x, int cnt_y, bool direction_ = false, int hollow = 0) {//기울기 및 절편 계산 함수

    if (a > 89.5) {                                     //그래프 각도 교정.(그래프의 기울기가 무한에 근접해야 y축과 평행해질 수 있기에
        //                  특정값 이상의 각도는 그래프상 의미가 없음
        //                  따라서 특정 각도가 넘으면 각도값을 초기화하고 이후 더해지는 각도값에 음수를 곱함)
        a = (a - 90) * -1;
    }
    // if (true) { // This 'if (true)' is unnecessary
    if (direction_ == true) {
        if (cnt_y >= (tan(a * (PI / 180)) * cnt_x) - b) { // 각도값 a를 라디안으로 변환 후 tan값을 계산
            // cnt_x를 곱한 값 - 절편을 뺀 값이
            // cnt_y보다 값이 작거나 같다면 참을 반환해
            // 반환값이 참인 경우에만 연산을 요청한 도형 함수에서
            // 리스트의 요소를 수정함
            return true; // 조건이 성립하므로 참 반환
        }
        else {
            return false;
        }
    }
    else { // direction_ == false (우측 절단)
        if (cnt_y <= (tan(a * (PI / 180)) * cnt_x) - b) {
            return true;
        }
        else {
            return false;
        }
    }
    // } // End of unnecessary if (true)
}

bool circle_c(int px, int py, int a, int b, int x, int y) {//x,y좌표 , x,y끝값 // px, py는 타원의 중심 좌표
    // Note: The comment // x,y좌표 , x,y끝값 doesn't quite match the usage in Circle function
    // where this is called as circle_c(x, y, xinc, yinc, j, i); implying x,y are center and xinc, yinc are radii.
    // The parameters in this function are px, py (center?), a, b (radii?), x, y (point to check?).
    // The calculation looks like it's checking if point (x, y) is within an ellipse centered at (px, py) with radii a, b.
    // Let's assume px, py are center and a, b are radii based on the equation.
    // The lines py = 2 * py - y; px = 2 * px - x; seem incorrect for calculating ellipse membership relative to a center.
    // These look like reflections or some custom coordinate transformation.
    // For a standard ellipse centered at (px, py) with radii a and b, the check for point (x, y) is:
    // ((x - px)^2 / a^2) + ((y - py)^2 / b^2) <= 1
    // The provided code uses pow(x - px, 2) / pow(a, 2) + pow(y - py, 2) / pow(b, 2) <= 1 which matches the standard equation,
    // but the py = 2*py - y; px = 2*px - x; lines before the check will alter the effective center being checked against.
    // This might be intentional for a specific effect, but it's non-standard ellipse check.
    // Keeping the code as provided but noting this potential point of confusion.

    // py = 2 * py - y; // Custom coordinate transformation?
    // px = 2 * px - x; // Custom coordinate transformation?

    if ((pow(x - px, 2) / pow(a, 2)) + (pow(y - py, 2) / pow(b, 2)) <= 1) {//타원의 방정식
        return true;
    }
    else {
        return false;
    }
}

void Charinput(int x, int y, char asci) {
    // Check bounds before writing to avoid errors
    if (x >= 0 && x < H_SIZE && y >= 0 && y < W_SIZE) {
        car[x][y] = int(asci);
    }
}

void printCar() {
    for (int i = 0; i < H_SIZE; i += 1) {
        for (int j = 0; j < W_SIZE; j += 1) {
            printf("%c", car[i][j]);//리스트에 저장된 정수형의 값을 문자로 변경하여 출력
        }
        printf("\n");
    }
}

//x좌표, y좌표, x크기, y크기, 사용할 문자, 덮어쓰기 여부, 외곽선 두께, 자르기 각도(기울기), 자르기 위치(절편), 자를 방향, j증가값, i증가값)
void Square(int x, int y, int xinc, int yinc, char r, bool cover, int stroke, float aa, int bb, bool direction, int wp, int hp) {
    // Applying default values if needed (already in prototype or handled by default args in C++). Assuming C-style default behavior is not used in definition.
    // Charinput defaults to ' ' (32), cover to 0, stroke to 0, aa to 1000, bb to 0, direction to false, wp/hp to 0
    if (r == '\0') r = ' '; // Handle default char if not set
    // bool cover = (bool)cover_int; // Cast int to bool if needed based on call

    if (aa < 1000 && aa > 89.5) {
        bb = (bb * -1 - xinc);//그래프 절편 교정
    }
    // Ensure stroke is non-negative for thickness calculation
    int effective_stroke = (stroke < 0) ? -stroke : stroke;

    if (effective_stroke > 0) { // Handle cases with stroke thickness
        if (aa != 1000.000000) { // With tanc cut
            if (cover == true) {
                // Clear the cut square area with space
                cnt_y = 1;
                cnt_x = 1;
                for (int i = y; i < y + yinc; i += 1) { // Note: Consider if hp/wp should affect clearing loop
                    cnt_y += 1;
                    for (int j = x; j < x + xinc; j += 1) { // Note: Consider if hp/wp should affect clearing loop
                        cnt_x += 1;
                        // Check bounds before writing
                        if (i >= 0 && i < H_SIZE && j >= 0 && j < W_SIZE) {
                            if (tanc(j, i, aa, bb, cnt_x, cnt_y, direction, effective_stroke) == true) {
                                car[i][j] = 32;
                            }
                        }
                    }
                    cnt_x = 1;
                }
                cnt_y = 1;
                cnt_x = 1;
                // Draw the stroke part within the cut square area
                for (int i = y; i < y + yinc; i = i + hp + 1) {
                    cnt_y += 1;
                    for (int j = x; j < x + xinc; j = j + wp + 1) {
                        cnt_x += 1;
                        // Check bounds before writing
                        if (i >= 0 && i < H_SIZE && j >= 0 && j < W_SIZE) {
                            // Check if pixel is within stroke boundary AND within tanc cut
                            if ((j >= x && j < x + effective_stroke) || (j >= x + xinc - effective_stroke && j < x + xinc) ||
                                (i >= y && i < y + effective_stroke) || (i >= y + yinc - effective_stroke && i < y + yinc)) {

                                if (tanc(j, i, aa, bb, cnt_x, cnt_y, direction) == true) {
                                    car[i][j] = int(r);
                                }
                            }
                            // Additional tanc check logic from original code - might be redundant or need review
                            // if (tanc(j, i, aa, bb, cnt_x, cnt_y, direction) == true) {
                            //     if (tanc(j, i, aa, bb - effective_stroke, cnt_x, cnt_y) == true) { // bb - stroke seems suspicious for outer stroke
                            //         car[i][j] = int(r);
                            //     }
                            // } else { // This else is for the inner tanc check, might be misplaced
                            //      if ((j >= x && j < x + effective_stroke) || (j >= x + xinc - effective_stroke && j < x + xinc) || (i >= y && i < y + effective_stroke) || (i >= y + yinc - effective_stroke && i < y + yinc)) {
                            //          if (tanc(j, i, aa, bb, cnt_x, cnt_y, direction) == true) {
                            //              car[i][j] = int(r);
                            //          }
                            //      }
                            //      if (tanc(j, i, aa, bb, cnt_x, cnt_y, 1) == true) { // Using direction=1 (true) here?
                            //          if (tanc(j, i, aa, bb - effective_stroke, cnt_x, cnt_y) == true) { // bb - stroke seems suspicious
                            //              car[i][j] = int(r);
                            //          }
                            //      }
                            // }
                        }
                    }
                    cnt_x = 1;
                }
            } // end cover == true (stroke > 0, aa != 1000)
            else { // cover == false (stroke > 0, aa != 1000)
                cnt_y = 1;
                cnt_x = 1;
                // Draw only the stroke part within the cut square area
                for (int i = y; i < y + yinc; i = i + hp + 1) {
                    cnt_y += 1;
                    for (int j = x; j < x + xinc; j = j + wp + 1) {
                        cnt_x += 1;
                        // Check bounds before writing
                        if (i >= 0 && i < H_SIZE && j >= 0 && j < W_SIZE) {
                            // Check if pixel is within stroke boundary AND within tanc cut
                            if ((j >= x && j < x + effective_stroke) || (j >= x + xinc - effective_stroke && j < x + xinc) ||
                                (i >= y && i < y + effective_stroke) || (i >= y + yinc - effective_stroke && i < y + yinc)) {

                                if (tanc(j, i, aa, bb, cnt_x, cnt_y, direction) == true) {
                                    car[i][j] = int(r);
                                }
                            }
                            // Duplicated/potentially incorrect tanc logic again
                            // if (x + effective_stroke - 1 >= j || x + xinc - effective_stroke <= j || y + effective_stroke - 1 >= i || y + yinc - effective_stroke <= i) {
                            //     if (tanc(j, i, aa, bb, cnt_x, cnt_y, direction) == true) {
                            //         car[i][j] = int(r);
                            //     }
                            // }
                            // if (tanc(j, i, aa, bb, cnt_x, cnt_y, 1) == true) {
                            //      if (tanc(j, i, aa, bb - effective_stroke, cnt_x, cnt_y) == true) { // bb - stroke seems suspicious
                            //          car[i][j] = int(r);
                            //      }
                            // }
                        }
                    }
                    cnt_x = 1;
                }
            } // end cover == false (stroke > 0, aa != 1000)
        }
        else { // aa == 1000 (stroke > 0, no tanc cut)
            if (cover == true) {
                // Clear the entire square area if cover is true? Or only inside stroke?
                // Based on the Circle function logic, clearing the whole area seems intended.
                for (int i = y; i < y + yinc; i += 1) { // Note: Consider if hp/wp should affect clearing loop
                    for (int j = x; j < x + xinc; j += 1) { // Note: Consider if hp/wp should affect clearing loop
                        // Check bounds before writing
                        if (i >= 0 && i < H_SIZE && j >= 0 && j < W_SIZE) {
                            car[i][j] = 32; // cover가 true이므로 기존 배경을 지정한 좌표만큼만 공백으로 덮음
                        }
                    }
                }
                // Then draw the stroke
                for (int i = y; i < y + yinc; i = i + hp + 1) { // Note: Consider if hp/wp should affect stroke loop
                    for (int j = x; j < x + xinc; j = j + wp + 1) { // Note: Consider if hp/wp should affect stroke loop
                        // Check bounds before writing
                        if (i >= 0 && i < H_SIZE && j >= 0 && j < W_SIZE) {
                            if ((j >= x && j < x + effective_stroke) || (j >= x + xinc - effective_stroke && j < x + xinc) ||
                                (i >= y && i < y + effective_stroke) || (i >= y + yinc - effective_stroke && i < y + yinc)) {
                                car[i][j] = int(r); // 지정한 좌표에 해당하는 리스트의 값을 설정한 문자값으로 변경
                            }
                        }
                    }
                }
            }
            else { // cover == false (stroke > 0, aa == 1000, no tanc cut)
                // Draw only the stroke
                for (int i = y; i < y + yinc; i = i + hp + 1) { // Note: Consider if hp/wp should affect loop
                    for (int j = x; j < x + xinc; j = j + wp + 1) { // Note: Consider if hp/wp should affect loop
                        // Check bounds before writing
                        if (i >= 0 && i < H_SIZE && j >= 0 && j < W_SIZE) {
                            if ((j >= x && j < x + effective_stroke) || (j >= x + xinc - effective_stroke && j < x + xinc) ||
                                (i >= y && i < y + effective_stroke) || (i >= y + yinc - effective_stroke && i < y + yinc)) {
                                car[i][j] = int(r);
                            }
                        }
                    }
                }
            }
        }
    }
    else { // effective_stroke == 0
        if (aa != 1000.000000) { // stroke == 0, tanc cut
            if (cover == true) {
                cnt_y = 1;
                cnt_x = 1;
                // Clear the cut area with space
                for (int i = y; i < y + yinc; i += 1) { // Note: Consider if hp/wp should affect clearing loop
                    cnt_y += 1;
                    for (int j = x; j < x + xinc; j += 1) { // Note: Consider if hp/wp should affect clearing loop
                        cnt_x += 1;
                        // Check bounds before writing
                        if (i >= 0 && i < H_SIZE && j >= 0 && j < W_SIZE) {
                            if (tanc(j, i, aa, bb, cnt_x, cnt_y, direction) == true) {
                                car[i][j] = 32;
                            }
                        }
                    }
                    cnt_x = 1;
                }
                cnt_y = 1;
                cnt_x = 1;
                // Fill the cut area with character
                for (int i = y; i < y + yinc; i = i + hp + 1) {
                    cnt_y += 1;
                    for (int j = x; j < x + xinc; j = j + wp + 1) {
                        cnt_x += 1;
                        // Check bounds before writing
                        if (i >= 0 && i < H_SIZE && j >= 0 && j < W_SIZE) {
                            if (tanc(j, i, aa, bb, cnt_x, cnt_y, direction) == true)
                                car[i][j] = int(r);
                        }
                    }
                    cnt_x = 1;
                }
            }
            else { // stroke == 0, tanc cut, cover == false
                cnt_y = 1;
                cnt_x = 1;
                // Fill the cut area with character directly
                for (int i = y; i < y + yinc; i = i + hp + 1) {
                    cnt_y += 1;
                    for (int j = x; j < x + xinc; j = j + wp + 1) {
                        cnt_x += 1;
                        // Check bounds before writing
                        if (i >= 0 && i < H_SIZE && j >= 0 && j < W_SIZE) {
                            if (tanc(j, i, aa, bb, cnt_x, cnt_y, direction) == true) {
                                car[i][j] = int(r);
                            }
                        }
                    }
                    cnt_x = 1;
                }
            }
        }
        else { // stroke == 0, no tanc cut (aa == 1000)
            if (cover == true) {
                // Clear the entire square area
                for (int i = y; i < y + yinc; i += 1) { // Note: Consider if hp/wp should affect clearing loop
                    for (int j = x; j < x + xinc; j += 1) { // Note: Consider if hp/wp should affect clearing loop
                        // Check bounds before writing
                        if (i >= 0 && i < H_SIZE && j >= 0 && j < W_SIZE) {
                            car[i][j] = 32; // cover가 true이므로 기존 배경을 지정한 좌표만큼만 공백으로 덮음
                        }
                    }
                }
                // Fill the entire square area with character
                for (int i = y; i < y + yinc; i = i + hp + 1) { // Note: Consider if hp/wp should affect filling loop
                    for (int j = x; j < x + xinc; j = j + wp + 1) { // Note: Consider if hp/wp should affect filling loop
                        // Check bounds before writing
                        if (i >= 0 && i < H_SIZE && j >= 0 && j < W_SIZE) {
                            car[i][j] = int(r); // 지정한 좌표에 해당하는 리스트의 값을 설정한 문자값으로 변경
                        }
                    }
                }
            }
            else { // stroke == 0, no tanc cut, cover == false
                // Fill the entire square area with character directly
                for (int i = y; i < y + yinc; i = i + hp + 1) { // Note: Consider if hp/wp should affect loop
                    for (int j = x; j < x + xinc; j = j + wp + 1) { // Note: Consider if hp/wp should affect loop
                        // Check bounds before writing
                        if (i >= 0 && i < H_SIZE && j >= 0 && j < W_SIZE) {
                            car[i][j] = int(r);
                        }
                    }
                }
            }
        }
    }
}


void Circle(int x, int y, int xinc, int yinc, char r, bool cover, int stroke, float aa, int bb, bool direction, int wp, int hp) {
    // Applying default values if needed (already in prototype or handled by default args in C++). Assuming C-style default behavior is not used in definition.
    // Charinput defaults to ' ' (32), cover to 0, stroke to 0, aa to 1000, bb to 0, direction to false, wp/hp to 0
    if (r == '\0') r = ' '; // Handle default char if not set
    // bool cover = (bool)cover_int; // Cast int to bool if needed based on call


    // Ensure stroke is non-negative for thickness calculation
    int effective_stroke = (stroke < 0) ? -stroke : stroke;

    if (effective_stroke > 0) { // Handle cases with stroke thickness
        if (aa != 1000.000000) { // With tanc cut
            if (cover == true) {
                cnt_y = 1;
                cnt_x = 1;
                // Clear the cut circle area with space
                for (int i = y - (yinc); i < y + yinc; i = i + hp + 1) { // Note: Consider if hp/wp should affect clearing loop
                    cnt_y += 1;
                    for (int j = x - (xinc); j < x + xinc; j = j + wp + 1) { // Note: Consider if hp/wp should affect clearing loop
                        cnt_x += 1;
                        // Check bounds before writing
                        if (i >= 0 && i < H_SIZE && j >= 0 && j < W_SIZE) {
                            if (tanc(j, i, aa, bb, cnt_x, cnt_y, direction, effective_stroke) == true && circle_c(x, y, xinc, yinc, j, i) == true) {
                                car[i][j] = 32;
                            }
                        }
                    }
                    cnt_x = 1;
                }
                cnt_y = 1;
                cnt_x = 1;
                // Draw the stroke part within the cut circle area
                for (int i = y - (yinc); i < y + yinc; i = i + hp + 1) {
                    cnt_y += 1;
                    for (int j = x - (xinc); j < x + xinc; j = j + wp + 1) {
                        cnt_x += 1;
                        // Check bounds before writing
                        if (i >= 0 && i < H_SIZE && j >= 0 && j < W_SIZE) {
                            // Check if pixel is outside the inner circle/ellipse AND inside the outer circle/ellipse
                            if (circle_c(x, y, xinc, yinc, j, i) == true && circle_c(x, y, xinc - effective_stroke, yinc - effective_stroke, j, i) == false) {
                                // Check if pixel is also within the tanc cut
                                if (tanc(j, i, aa, bb, cnt_x, cnt_y, direction) == true) {
                                    car[i][j] = int(r);
                                }
                            }
                            // The following section from the original code looks potentially duplicated or incorrect.
                            // Keeping it commented out as it might cause unintended behavior.
                            // if (tanc(j, i, aa, bb, cnt_x, cnt_y, direction) == true && circle_c(x, y, xinc, yinc, j, i)) {
                            //     if (tanc(j, i, aa, bb - effective_stroke / 2, cnt_x, cnt_y) == true) { // bb - stroke / 2 seems suspicious
                            //         car[i][j] = int(r);
                            //     }
                            // }
                            // else { // This else is for the inner tanc check, might be misplaced
                            //     if (circle_c(x, y, xinc - effective_stroke, yinc - effective_stroke, j, i) == false) {
                            //         if (tanc(j, i, aa, bb, cnt_x, cnt_y, direction) == true && circle_c(x, y, xinc, yinc, j, i) == true) {
                            //             car[i][j] = int(r);
                            //         }
                            //     }
                            //     if (tanc(j, i, aa, bb, cnt_x, cnt_y, 1) == true && circle_c(x, y, xinc, yinc, j, i)) {
                            //         if (tanc(j, i, aa, bb - effective_stroke / 2, cnt_x, cnt_y) == true) {
                            //             car[i][j] = int(r);
                            //         }
                            //     }
                            // }
                        }
                    }
                    cnt_x = 1;
                }
            } // end cover == true (stroke != 0, aa != 1000)
            else { // cover == false (stroke != 0, aa != 1000)
                cnt_y = 1;
                cnt_x = 1;
                // Draw only the stroke part within the cut circle area
                for (int i = y - (yinc); i < y + yinc; i = i + hp + 1) {
                    cnt_y += 1;
                    for (int j = x - (xinc); j < x + xinc; j = j + wp + 1) {
                        cnt_x += 1;
                        // Check bounds before writing
                        if (i >= 0 && i < H_SIZE && j >= 0 && j < W_SIZE) {
                            // Check if pixel is outside the inner circle/ellipse AND inside the outer circle/ellipse
                            if (circle_c(x, y, xinc, yinc, j, i) == true && circle_c(x, y, xinc - effective_stroke, yinc - effective_stroke, j, i) == false) {
                                // Check if pixel is also within the tanc cut
                                if (tanc(j, i, aa, bb, cnt_x, cnt_y, direction) == true) {
                                    car[i][j] = int(r);
                                }
                            }
                            // The following section from the original code looks potentially duplicated or incorrect.
                           // Keeping it commented out as it might cause unintended behavior.
                            // if (direction == true) {
                            //     if (circle_c(x, y, xinc - effective_stroke, yinc - effective_stroke, j, i) == false) {
                            //         if (tanc(j, i, aa, bb, cnt_x, cnt_y, direction) == true && circle_c(x, y, xinc, yinc, j, i) == true) {
                            //             car[i][j] = int(r);
                            //         }
                            //     }
                            //     if (tanc(j, i, aa, bb, cnt_x, cnt_y, direction) == true && circle_c(x, y, xinc, yinc, j, i)) {
                            //         if (tanc(j, i, aa, bb - effective_stroke / 2, cnt_x, cnt_y) == true) {
                            //             car[i][j] = int(r);
                            //         }
                            //     }
                            // } else {
                            //     if (circle_c(x, y, xinc - effective_stroke, yinc - effective_stroke, j, i) == false) {
                            //         if (tanc(j, i, aa, bb, cnt_x, cnt_y, direction) == true && circle_c(x, y, xinc, yinc, j, i) == true) {
                            //             car[i][j] = int(r);
                            //         }
                            //     }
                            //     if (tanc(j, i, aa, bb, cnt_x, cnt_y, 1) == true && circle_c(x, y, xinc, yinc, j, i)) {
                            //         if (tanc(j, i, aa, bb - effective_stroke / 2, cnt_x, cnt_y) == true) {
                            //             car[i][j] = int(r);
                            //         }
                            //     }
                            // }
                        }
                    }
                    cnt_x = 1;
                }
            } // end cover == false (stroke != 0, aa != 1000)
        }
        else { // aa == 1000 (stroke != 0, no tanc cut)
            if (cover == true) {
                // Clear the entire circle area if cover is true? Or only inside stroke?
                // Based on the code, clearing the whole area seems intended.
                for (int i = y - (yinc); i < y + yinc; i += 1) { // Note: Consider if hp/wp should affect clearing loop
                    for (int j = x - (xinc); j < x + xinc; j += 1) { // Note: Consider if hp/wp should affect clearing loop
                        // Check bounds before writing
                        if (i >= 0 && i < H_SIZE && j >= 0 && j < W_SIZE) {
                            if (circle_c(x, y, xinc, yinc, j, i) == true)
                                car[i][j] = 32;
                        }
                    }
                }
                // Then draw the stroke
                for (int i = y - (yinc); i < y + yinc; i = i + hp + 1) {
                    for (int j = x - (xinc); j < x + xinc; j = j + wp + 1) {
                        // Check bounds before writing
                        if (i >= 0 && i < H_SIZE && j >= 0 && j < W_SIZE) {
                            // Check if pixel is outside the inner circle/ellipse AND inside the outer circle/ellipse
                            if (circle_c(x, y, xinc, yinc, j, i) == true && circle_c(x, y, xinc - effective_stroke, yinc - effective_stroke, j, i) == false)
                                car[i][j] = int(r);
                        }
                    }
                }
            }
            else { // cover == false (stroke != 0, aa == 1000, no tanc cut)
                // Draw only the stroke
                for (int i = y - (yinc); i < y + yinc; i = i + hp + 1) {
                    for (int j = x - (xinc); j < x + xinc; j = j + wp + 1) {
                        // Check bounds before writing
                        if (i >= 0 && i < H_SIZE && j >= 0 && j < W_SIZE) {
                            // Check if pixel is outside the inner circle/ellipse AND inside the outer circle/ellipse
                            if (circle_c(x, y, xinc, yinc, j, i) == true && circle_c(x, y, xinc - effective_stroke, yinc - effective_stroke, j, i) == false) {
                                car[i][j] = int(r);
                            }
                        }
                    }
                }
            }
        }
    }
    else { // effective_stroke == 0
        if (aa != 1000.000000) { // stroke == 0, tanc cut
            if (cover == true) {
                cnt_y = 1;
                cnt_x = 1;
                // Clear the cut circle area with space
                for (int i = y - (yinc); i < y + yinc; i = i + hp + 1) { // Note: Consider if hp/wp should affect clearing loop
                    cnt_y += 1;
                    for (int j = x - (xinc); j < x + xinc; j = j + wp + 1) { // Note: Consider if hp/wp should affect clearing loop
                        cnt_x += 1;
                        // Check bounds before writing
                        if (i >= 0 && i < H_SIZE && j >= 0 && j < W_SIZE) {
                            if (tanc(j, i, aa, bb, cnt_x, cnt_y, direction) == true && circle_c(x, y, xinc, yinc, j, i) == true) {
                                car[i][j] = 32;
                            }
                        }
                    }
                    cnt_x = 1;
                }
                cnt_y = 1;
                cnt_x = 1;
                // Fill the cut circle area with character
                for (int i = y - (yinc); i < y + yinc; i = i + hp + 1) {
                    cnt_y += 1;
                    for (int j = x - (xinc); j < x + xinc; j = j + wp + 1) {
                        cnt_x += 1;
                        // Check bounds before writing
                        if (i >= 0 && i < H_SIZE && j >= 0 && j < W_SIZE) {
                            if (tanc(j, i, aa, bb, cnt_x, cnt_y, direction) == true && circle_c(x, y, xinc, yinc, j, i) == true) {
                                car[i][j] = int(r);
                            }
                        }
                    }
                    cnt_x = 1;
                }
            }
            else { // stroke == 0, tanc cut, cover == false
                cnt_y = 1;
                cnt_x = 1;
                // Fill the cut circle area with character directly
                for (int i = y - (yinc); i < y + yinc; i = i + hp + 1) {
                    cnt_y += 1;
                    for (int j = x - (xinc); j < x + xinc; j = j + wp + 1) {
                        cnt_x += 1;
                        // Check bounds before writing
                        if (i >= 0 && i < H_SIZE && j >= 0 && j < W_SIZE) {
                            if (tanc(j, i, aa, bb, cnt_x, cnt_y, direction) == true && circle_c(x, y, xinc, yinc, j, i) == true) {
                                car[i][j] = int(r);
                            }
                        }
                    }
                    cnt_x = 1;
                }
            }
        }
        else { // stroke == 0, no tanc cut (aa == 1000)
            if (cover == true) {
                // Clear the entire circle area if cover is true?
                // Based on the code, clearing the whole area seems intended.
                for (int i = y - (yinc); i < y + yinc; i += 1) { // Note: Consider if hp/wp should affect clearing loop
                    for (int j = x - (xinc); j < x + xinc; j += 1) { // Note: Consider if hp/wp should affect clearing loop
                        // Check bounds before writing
                        if (i >= 0 && i < H_SIZE && j >= 0 && j < W_SIZE) {
                            if (circle_c(x, y, xinc, yinc, j, i) == true)
                                car[i][j] = 32;
                        }
                    }
                }
                // Fill the entire circle area with character
                for (int i = y - (yinc); i < y + yinc; i = i + hp + 1) { // Note: Consider if hp/wp should affect filling loop
                    for (int j = x - (xinc); j < x + xinc; j = j + wp + 1) { // Note: Consider if hp/wp should affect filling loop
                        // Check bounds before writing
                        if (i >= 0 && i < H_SIZE && j >= 0 && j < W_SIZE) {
                            if (circle_c(x, y, xinc, yinc, j, i) == true)
                                car[i][j] = int(r);
                        }
                    }
                }
            }
            else { // stroke == 0, no tanc cut, cover == false
                // Fill the entire circle area with character directly
                for (int i = y - (yinc); i < y + yinc; i = i + hp + 1) { // Note: Consider if hp/wp should affect loop
                    for (int j = x - (xinc); j < x + xinc; j = j + wp + 1) { // Note: Consider if hp/wp should affect loop
                        // Check bounds before writing
                        if (i >= 0 && i < H_SIZE && j >= 0 && j < W_SIZE) {
                            if (circle_c(x, y, xinc, yinc, j, i) == true) {
                                car[i][j] = int(r);
                            }
                        }
                    }
                }
            }
        }
    }
}


int main() { // Changed to int main() for standard compliance
    initializeCar();//공백으로 초기화
    //main
    // canvas max size 0,0 235x64
    //--------------------------------------------------------------
    // #Square(x좌표,y좌표,x증가값,y증가값,채우기모양(아스키) ,cover(bool) ,stroke(int),a(double) ,b(int) ,direction(bool),wp(int) ,hp(int) )
    // direction은 true(1)일때 그래프 기준 좌측으로 문자가 입력됨
    //             false(0)일때는 그래프 기준 우측
    //
    // x좌표(int) ,y좌표(int) ,
    // x좌표 끝값(int) ,y좌표 끝값(int) ,
    // [Null 불허]
    // - - - - - - - - - - - - - - - - -
    // 아스키값(int)(기본=32(공백)) ,
    // 덮어쓰기여부(bool) ,외곽선 두께(int) ,
    // 잘라내기 각도(float),잘라내기 절편(int),
    // 잘라내기 방향(bool), wp,hp(int)x,y줄무늬
    // [Null 허용]
    //--------------------------------------------------------------
    //--------------------------------------------------------------
    //             Tool Box                                        |
    // -------------------------------------------------------------
    //
//------------------------------------------------------------------------------------------------------
//  Please edit only this section!
//------------------------------------------------------------------------------------------------------
   // printf("메뉴를 입력하세요");
   // scanf("%d", menu);
    int mt_x = 0, mt_y = 0;
    //줄무늬 또는 특정 패턴으로 배경 만들기
    //물방울처럼 빛 반사되는거 표현
   //체크무늬 배경_1-------------------------------------------------
    for (int i = 0;i < W_SIZE;i = i + 20) {
        Square(0, 0, 235, 64, '+', 0, 0, 45, i - 30, 0, 0, 0); // Added wp, hp = 0 based on definition/prototype
        i += 20;

        Square(0, 0, 235, 64, '.', 1, 0, 45, i - 30, 0, 0, 0); // Added wp, hp = 0

    }

    for (int i = -20;i < H_SIZE - 10;i = i + 20) {
        Square(0, 0 + i + 20, 235, 10, '=', 0, 0, 45, i - 11, 0, 0, 1); // Added wp = 0
    }
    //----------------------------------------------------------------
    //


    //met_1-------------------------------------------------------------
    mt_x = 65;
    mt_y = 5;
    //그림자
    Circle(mt_x + 125, mt_y + 46 + 3, 100, 13, ' ', 0, 0, 1000, 0, 0, 0, 0); // Added default args

    Square(mt_x + 100 - 8, mt_y + 10 + 3, 65 - 15, 37, '@', 0, 0, 1000, 0, 0, 0, 0); // Added default args

    Circle(mt_x + 139 - 8, mt_y + 10 + 3, 20, 9, '@', 0, 0, 1000, 0, 0, 0, 0); // Added default args

    Circle(mt_x + 114 - 3, mt_y + 9 + 2, 14, 7, '@', 0, 0, 1000, 0, 0, 0, 0); // Added default args
    Square(mt_x + 120 - 8, mt_y + 8 + 2, 13, 3, '@', 0, 0, 1000, 0, 0, 0, 0); // Added default args
    Square(mt_x + 104 - 4, mt_y + 5 + 2, 5, 5, '@', 0, 0, 100, 1, 1, 0, 0); // Added default args

    Circle(mt_x + 100 - 9, mt_y + 14, 29, 5, '@', 0, 0, 1000, 0, 0, 0, 0); // Added default args
    Square(mt_x + 104 - 4, mt_y + 5 + 2, 5, 10, '@', 0, 0, 100, 1, 1, 0, 0); // Added default args

    Circle(mt_x + 100 - 9, mt_y + 15, 29, 7, '@', 0, 0, 1000, 0, 0, 0, 0);//왼팔 - Added default args
    Circle(mt_x + 100 - 19, mt_y + 16, 8, 11, '@', 0, 0, 100, -13, 1, 0, 0); // Added default args

    Circle(mt_x + 100 - 23, mt_y + 43, 29, 11, '@', 0, 0, 1000, 0, 0, 0, 0);//왼발 - Added default args
    Circle(mt_x + 100 - 34, mt_y + 41, 7, 7, '@', 0, 0, 1000, 0, 0, 0, 0); // Added default args
    Square(mt_x + 145, mt_y + 21 - 5, 13, 7, '@', 0, 0, 18, -4, 1, 0, 0); // Added default args
    Square(mt_x + 100 - 16, mt_y + 41, 10, 10, '@', 0, 0, 8, -9, 0, 0, 0); // Added direction=0, wp, hp = 0

    Square(mt_x + 50 + 31, mt_y + 0 + 16, 12, 28, '@', 0, 0, 1000, 0, 0, 0, 0); // Added default args
    Square(mt_x + 50 + 20, mt_y + 0 + 16, 12, 28, '@', 0, 0, 140, 14, 1, 0, 0); // Added default args
    Square(mt_x + 50 + 16, mt_y + 0 + 16, 12, 28, '@', 0, 0, 118, 12, 1, 0, 0); // Added default args

    Circle(mt_x + 116, mt_y + 43 + 5, 52, 9, '@', 0, 0, 1000, 0, 0, 0, 0);//?? - Added default args

    Circle(mt_x + 157, mt_y + 41 + 4, 22, 11, '@', 0, 0, 1000, 0, 0, 0, 0);//오른발 - Added default args
    Square(mt_x + 154, mt_y + 41 - 5, 13, 7, '@', 0, 0, 40, 3, 1, 0, 0); // Added default args

    Circle(mt_x + 157, mt_y + 21 + 4, 13, 7, '@', 0, 0, 17, -1, 1, 0, 0);//오른팔 - Added default args
    Square(mt_x + 150 + 7, mt_y + 28, 2, 2, '@', 0, 0, 1000, 0, 0, 0, 0); // Added default args

    Square(mt_x + 140, mt_y + 14, 17, 36, '@', 0, 0, 45, 2, 1, 0, 0); // Added default args

    //눈
    Square(mt_x + 108, mt_y + 14, 2, 1, ' ', 0, 0, 1000, 0, 0, 0, 0); // Added default args
    Square(mt_x + 125, mt_y + 16, 2, 1, ' ', 0, 0, 1000, 0, 0, 0, 0); // Added default args
    //입
    Circle(mt_x + 120, mt_y + 14, 30, 9, ' ', 0, -2, 5, -11, 1, 0, 0); // Added default args
    //--------------------------------------------------------------------

    //met_2-------------------------------------------------------------
    //main
    mt_x = -55;
    mt_y = 0;
    //그림자
    Circle(mt_x + 127, mt_y + 45 + 3, 103, 17, ' ', 0, 0, 1000, 0, 0, 0, 0); // Added default args

    Square(mt_x + 100 - 8, mt_y + 10 + 3, 65 - 15, 37, '@', 0, 0, 1000, 0, 0, 0, 0); // Added default args

    Circle(mt_x + 139 - 8, mt_y + 10 + 3, 20, 9, '@', 0, 0, 1000, 0, 0, 0, 0); // Added default args

    Circle(mt_x + 114 - 3, mt_y + 9 + 2, 14, 7, '@', 0, 0, 1000, 0, 0, 0, 0); // Added default args
    Square(mt_x + 120 - 8, mt_y + 8 + 2, 13, 3, '@', 0, 0, 1000, 0, 0, 0, 0); // Added default args
    Square(mt_x + 104 - 4, mt_y + 5 + 2, 5, 5, '@', 0, 0, 100, 1, 1, 0, 0); // Added default args

    Circle(mt_x + 100 - 9, mt_y + 14, 29, 5, '@', 0, 0, 1000, 0, 0, 0, 0); // Added default args
    Square(mt_x + 104 - 4, mt_y + 5 + 2, 5, 10, '@', 0, 0, 100, 1, 1, 0, 0); // Added default args

    Circle(mt_x + 100 - 9, mt_y + 15, 29, 7, '@', 0, 0, 1000, 0, 0, 0, 0);//왼팔 - Added default args
    Circle(mt_x + 100 - 19, mt_y + 16, 8, 11, '@', 0, 0, 100, -13, 1, 0, 0); // Added default args
    Square(mt_x + 50 + 16, mt_y + 0 + 16, 12, 31, '@', 0, 0, 118, 12, 1, 0, 0); // Added default args
    Circle(mt_x + 100 - 23, mt_y + 43, 29, 11, '$', 0, -6, 2, -12, 1, 0, 0); // Added default args
    Square(mt_x + 50 + 20, mt_y + 0 + 16, 14, 30, '@', 0, 0, 140, 14, 1, 0, 0); // Added default args
    Circle(mt_x + 100 - 34, mt_y + 41, 7, 7, '@', 0, 0, 1000, 0, 0, 0, 0); // Added default args
    Square(mt_x + 145, mt_y + 21 - 5, 13, 7, '@', 0, 0, 18, -4, 1, 0, 0); // Added default args
    Square(mt_x + 100 - 16, mt_y + 41, 10, 10, '$', 0, 0, 8, -9, 0, 0, 0); // Added direction=0, wp, hp=0
    Square(mt_x + 50 + 31, mt_y + 0 + 16, 13, 31, '@', 0, 0, 1000, 0, 0, 0, 0); // Added default args
    Circle(mt_x + 116, mt_y + 43 + 5, 52, 9, '@', 0, 0, 1000, 0, 0, 0, 0);//?? - Added default args
    // Square(mt_x + 81, mt_y + 37, 10, 10, '3',0,0,35,0,1);
    // Square(mt_x + 91, mt_y + 41, 50, 9, '3');
    Circle(mt_x + 116, mt_y + 43 + 5, 52, 9, '$', 0, -6, 2, -9, 1, 0, 0);//?? - Added default args

    //------------------------------------------------------------------------------------------------------
    //  End of editable section (or drawing calls)
    //------------------------------------------------------------------------------------------------------

    printCar(); // 저장된 그림 정보를 화면에 출력합니다.

    return 0; // Changed to int main() and added return 0;
}
