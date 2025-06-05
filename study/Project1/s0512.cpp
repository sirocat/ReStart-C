#include <stdio.h>
#include <cmath>//pi및 tan값 계산을 위해 사용
#define W_SIZE 235//캔버스 너비
#define H_SIZE 65//캔버스 높이
int car[H_SIZE][W_SIZE];//배열 크기 선언
int cnt_x, cnt_y, menu;              //1부터 시작하지 않는 for문의 j값을 변환하기 위한 변수
//1부터 시작하지 않는 for문의 i값을 변환하기 위한 변수
const double PI = acos(-1.0);//pi 선언 // Note: std::acos might need <cmath> include, plain acos is standard C

//네모 타원 문자열 그라데이션
// @@@@@@@###$$$====***!!!;;;;:::~~~----,,,...
void initializeCar() {
    // 전체 배열을 공백으로 초기화
    for (int i = 0; i < H_SIZE; i++) {
        for (int j = 0; j < W_SIZE; j++) {
            car[i][j] = 32;
        }
    }
}
//       다른 도형 함수로부터 입력된 for문(줄여서 그냥 for문이라 하겠음)
//   x : for문의 j값 | a : 기울기(각도) | cnt_x :  for문의 j값에사 도형 x좌표를 뺀값
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
    if (true) { // Note: This 'if (true)' is always true and can be removed.
        if (direction_ == true) {
            if (cnt_y >= (tan(a * (PI / 180)) * cnt_x) - b) {//각도값 a를 라디안으로 변환 후 tan값을 계산,
                //cnt_x를 곱한 값 - 절편을 뺀 값이
                //cnt_y보다 값이 작거나 같다면 참을 반환해
                //반환값이 참인 경우에만 연산을 요청한 도형 함수에서
                //리스트의 요소를 수정함

                return true;//조건이 성립하므로 참 반환
            }
            else {
                return false;
            }
        }
        else {
            if (cnt_y <= (tan(a * (PI / 180)) * cnt_x) - b) {//우측 절단
                return true;
            }
            else {
                return false;
            }
        }
    }
}

bool circle_c(int px, int py, int a, int b, int x, int y) {//x,y좌표 , x,y끝값
    py = 2 * py - y;//값 교정
    px = 2 * px - x;

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
void Square(int x, int y, int xinc, int yinc, char r = ' ', bool cover = 0, int stroke = 0, float aa = 1000, int bb = 0, bool direction = false, int wp = 0, int hp = 0) {
    if (aa < 1000 && aa > 89.5) {
        bb = (bb * -1 - xinc);//그래프 절편 교정
    }
    // Ensure stroke is non-negative for thickness calculation
    int effective_stroke = (stroke < 0) ? -stroke : stroke;

    if (stroke != 0) { // Combined stroke > 0 and stroke < 0 cases for thickness
        if (aa != 1000.000000) {
            if (cover == true) {
                cnt_y = 1;
                cnt_x = 1;
                for (int i = y; i < y + yinc; i += 1) {
                    cnt_y += 1;
                    for (int j = x; j < x + xinc; j += 1) {
                        cnt_x += 1;
                        if (tanc(j, i, aa, bb, cnt_x, cnt_y, direction, effective_stroke) == true) {
                            car[i][j] = 32;
                        }
                    }
                    cnt_x = 1;
                }
                cnt_y = 1;
                cnt_x = 1;
                for (int i = y; i < y + yinc; i = i + hp + 1) {
                    cnt_y += 1;
                    for (int j = x; j < x + xinc; j = j + wp + 1) {
                        cnt_x += 1;
                        // Check bounds before writing
                        if (i >= 0 && i < H_SIZE && j >= 0 && j < W_SIZE) {
                            if (direction == true) {
                                // Logic for left cut and outer/inner stroke boundary
                                if ((j >= x && j < x + effective_stroke) || (j >= x + xinc - effective_stroke && j < x + xinc) ||
                                    (i >= y && i < y + effective_stroke) || (i >= y + yinc - effective_stroke && i < y + yinc)) {

                                    if (tanc(j, i, aa, bb, cnt_x, cnt_y, direction) == true) {
                                        car[i][j] = int(r);
                                    }
                                }
                                // Additional tanc check? This part might need careful review
                                // if (tanc(j, i, aa, bb, cnt_x, cnt_y, direction) == true) {
                                //     if (tanc(j, i, aa, bb - effective_stroke, cnt_x, cnt_y) == true) { // bb - stroke seems suspicious for outer stroke
                                //         car[i][j] = int(r);
                                //     }
                                // }
                            }
                            else { // direction == false
                                // Logic for right cut and outer/inner stroke boundary
                                if ((j >= x && j < x + effective_stroke) || (j >= x + xinc - effective_stroke && j < x + xinc) ||
                                    (i >= y && i < y + effective_stroke) || (i >= y + yinc - effective_stroke && i < y + yinc)) {

                                    if (tanc(j, i, aa, bb, cnt_x, cnt_y, direction) == true) {
                                        car[i][j] = int(r);
                                    }
                                }
                                // Additional tanc check? This part might need careful review
                                // if (tanc(j, i, aa, bb, cnt_x, cnt_y, 1) == true) { // Using direction=1 (true) here?
                                //     if (tanc(j, i, aa, bb - effective_stroke, cnt_x, cnt_y) == true) { // bb - stroke seems suspicious
                                //         car[i][j] = int(r);
                                //     }
                                // }
                            }
                        }
                    }
                    cnt_x = 1;
                }
            } // end cover == true (stroke > 0, aa != 1000)
            else { // cover == false (stroke > 0, aa != 1000)
                cnt_y = 1;
                cnt_x = 1;
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
                for (int i = y; i < y + yinc; i += 1) {
                    for (int j = x; j < x + xinc; j += 1) {
                        // Check bounds before writing
                        if (i >= 0 && i < H_SIZE && j >= 0 && j < W_SIZE) {
                            car[i][j] = 32; // cover가 true이므로 기존 배경을 지정한 좌표만큼만 공백으로 덮음
                        }
                    }
                }
                // Then draw the stroke
                for (int i = y; i < y + yinc; i = i + hp + 1) { // Note: += 1 for normal loop, not i + hp + 1
                    for (int j = x; j < x + xinc; j = j + wp + 1) { // Note: += 1 for normal loop, not j + wp + 1
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
                for (int i = y; i < y + yinc; i = i + hp + 1) { // Note: += 1 for normal loop, not i + hp + 1
                    for (int j = x; j < x + xinc; j = j + wp + 1) { // Note: += 1 for normal loop, not j + wp + 1
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
    else { // stroke == 0
        if (aa != 1000.000000) { // stroke == 0, tanc cut
            if (cover == true) {
                cnt_y = 1;
                cnt_x = 1;
                // Clear the cut area with space
                for (int i = y; i < y + yinc; i += 1) { // Note: += 1 for normal loop, not i + hp + 1 or wp + 1
                    cnt_y += 1;
                    for (int j = x; j < x + xinc; j += 1) { // Note: += 1 for normal loop
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
                for (int i = y; i < y + yinc; i += 1) {
                    for (int j = x; j < x + xinc; j += 1) {
                        // Check bounds before writing
                        if (i >= 0 && i < H_SIZE && j >= 0 && j < W_SIZE) {
                            car[i][j] = 32; // cover가 true이므로 기존 배경을 지정한 좌표만큼만 공백으로 덮음
                        }
                    }
                }
                // Fill the entire square area with character
                for (int i = y; i < y + yinc; i = i + hp + 1) { // Note: += 1 for normal loop
                    for (int j = x; j < x + xinc; j = j + wp + 1) { // Note: += 1 for normal loop
                        // Check bounds before writing
                        if (i >= 0 && i < H_SIZE && j >= 0 && j < W_SIZE) {
                            car[i][j] = int(r); // 지정한 좌표에 해당하는 리스트의 값을 설정한 문자값으로 변경
                        }
                    }
                }
            }
            else { // stroke == 0, no tanc cut, cover == false
                // Fill the entire square area with character directly
                for (int i = y; i < y + yinc; i = i + hp + 1) { // Note: += 1 for normal loop
                    for (int j = x; j < x + xinc; j = j + wp + 1) { // Note: += 1 for normal loop
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

void Circle(int x, int y, int xinc, int yinc, char r = ' ', bool cover = 0, int stroke = 0, float aa = 1000, int bb = 0, bool direction = false, int wp = 0, int hp = 0) {
    // Ensure stroke is non-negative for thickness calculation
    int effective_stroke = (stroke < 0) ? -stroke : stroke;

    if (stroke != 0) { // Combined stroke > 0 and stroke < 0 cases
        if (aa != 1000.000000) { // With tanc cut
            if (cover == true) {
                cnt_y = 1;
                cnt_x = 1;
                // Clear the cut circle area with space
                for (int i = y - (yinc); i < y + yinc; i = i + hp + 1) { // Note: Consider if hp/wp should affect coverage clearing loop
                    cnt_y += 1;
                    for (int j = x - (xinc); j < x + xinc; j = j + wp + 1) { // Note: Consider if hp/wp should affect coverage clearing loop
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
                            // This section seems to have duplicated/potentially incorrect logic related to tanc and stroke
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
                            // Duplicated/potentially incorrect tanc logic again
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
                for (int i = y - (yinc); i < y + yinc; i = i + hp + 1) { // Note: Consider if hp/wp should affect clearing loop
                    for (int j = x - (xinc); j < x + xinc; j = j + wp + 1) { // Note: Consider if hp/wp should affect clearing loop
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
    else { // stroke == 0
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
                for (int i = y - (yinc); i < y + yinc; i = i + hp + 1) { // Note: += 1 for normal loop
                    for (int j = x - (xinc); j < x + xinc; j = j + wp + 1) { // Note: += 1 for normal loop
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
                for (int i = y - (yinc); i < y + yinc; i = i + hp + 1) { // Note: += 1 for normal loop
                    for (int j = x - (xinc); j < x + xinc; j = j + wp + 1) { // Note: += 1 for normal loop
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


void main() { // Note: Standard main function should return int (int main())
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
        Square(0, 0, 235, 64, '+', 0, 0, 45, i - 30, 0);
        i += 20;

        Square(0, 0, 235, 64, '.', 1, 0, 45, i - 30, 0);

    }

    for (int i = -20;i < H_SIZE - 10;i = i + 20) {
        Square(0, 0 + i + 20, 235, 10, '=', 0, 0, 45, i - 11, 0, 0, 1);
    }
    //----------------------------------------------------------------
    //


    //met_1-------------------------------------------------------------
    mt_x = 65;
    mt_y = 5;
    //그림자
    Circle(mt_x + 125, mt_y + 46 + 3, 100, 13, ' ');

    Square(mt_x + 100 - 8, mt_y + 10 + 3, 65 - 15, 37, '@');

    Circle(mt_x + 139 - 8, mt_y + 10 + 3, 20, 9, '@');

    Circle(mt_x + 114 - 3, mt_y + 9 + 2, 14, 7, '@');
    Square(mt_x + 120 - 8, mt_y + 8 + 2, 13, 3, '@');
    Square(mt_x + 104 - 4, mt_y + 5 + 2, 5, 5, '@', 0, 0, 100, 1, 1);

    Circle(mt_x + 100 - 9, mt_y + 14, 29, 5, '@');
    Square(mt_x + 104 - 4, mt_y + 5 + 2, 5, 10, '@', 0, 0, 100, 1, 1);

    Circle(mt_x + 100 - 9, mt_y + 15, 29, 7, '@');//왼팔
    Circle(mt_x + 100 - 19, mt_y + 16, 8, 11, '@', 0, 0, 100, -13, 1);

    Circle(mt_x + 100 - 23, mt_y + 43, 29, 11, '@');//왼발
    Circle(mt_x + 100 - 34, mt_y + 41, 7, 7, '@');
    Square(mt_x + 145, mt_y + 21 - 5, 13, 7, '@', 0, 0, 18, -4, 1);
    Square(mt_x + 100 - 16, mt_y + 41, 10, 10, '@', 0, 0, 8, -9);



    Square(mt_x + 50 + 31, mt_y + 0 + 16, 12, 28, '@');
    Square(mt_x + 50 + 20, mt_y + 0 + 16, 12, 28, '@', 0, 0, 140, 14, 1);
    Square(mt_x + 50 + 16, mt_y + 0 + 16, 12, 28, '@', 0, 0, 118, 12, 1);

    Circle(mt_x + 116, mt_y + 43 + 5, 52, 9, '@');//??

    Circle(mt_x + 157, mt_y + 41 + 4, 22, 11, '@');//오른발
    Square(mt_x + 154, mt_y + 41 - 5, 13, 7, '@', 0, 0, 40, 3, 1);


    Circle(mt_x + 157, mt_y + 21 + 4, 13, 7, '@', 0, 0, 17, -1, 1);//오른팔
    Square(mt_x + 150 + 7, mt_y + 28, 2, 2, '@');


    Square(mt_x + 140, mt_y + 14, 17, 36, '@', 0, 0, 45, 2, 1);

    //눈
    Square(mt_x + 108, mt_y + 14, 2, 1, ' ');
    Square(mt_x + 125, mt_y + 16, 2, 1, ' ');
    //입
    Circle(mt_x + 120, mt_y + 14, 30, 9, ' ', 0, -2, 5, -11, 1);
    //--------------------------------------------------------------------

    //met_2-------------------------------------------------------------
    //main
    mt_x = -55;
    mt_y = 0;
    //그림자
    Circle(mt_x + 127, mt_y + 45 + 3, 103, 17, ' ');

    Square(mt_x + 100 - 8, mt_y + 10 + 3, 65 - 15, 37, '@');

    Circle(mt_x + 139 - 8, mt_y + 10 + 3, 20, 9, '@');

    Circle(mt_x + 114 - 3, mt_y + 9 + 2, 14, 7, '@');
    Square(mt_x + 120 - 8, mt_y + 8 + 2, 13, 3, '@');
    Square(mt_x + 104 - 4, mt_y + 5 + 2, 5, 5, '@', 0, 0, 100, 1, 1);

    Circle(mt_x + 100 - 9, mt_y + 14, 29, 5, '@');
    Square(mt_x + 104 - 4, mt_y + 5 + 2, 5, 10, '@', 0, 0, 100, 1, 1);

    Circle(mt_x + 100 - 9, mt_y + 15, 29, 7, '@');//왼팔
    Circle(mt_x + 100 - 19, mt_y + 16, 8, 11, '@', 0, 0, 100, -13, 1);
    Square(mt_x + 50 + 16, mt_y + 0 + 16, 12, 31, '@', 0, 0, 118, 12, 1);
    Circle(mt_x + 100 - 23, mt_y + 43, 29, 11, '$', 0, -6, 2, -12, 1);
    Square(mt_x + 50 + 20, mt_y + 0 + 16, 14, 30, '@', 0, 0, 140, 14, 1);
    Circle(mt_x + 100 - 34, mt_y + 41, 7, 7, '@');
    Square(mt_x + 145, mt_y + 21 - 5, 13, 7, '@', 0, 0, 18, -4, 1);
    Square(mt_x + 100 - 16, mt_y + 41, 10, 10, '$', 0, 0, 8, -9);
    Square(mt_x + 50 + 31, mt_y + 0 + 16, 13, 31, '@');
    Circle(mt_x + 116, mt_y + 43 + 5, 52, 9, '@');//??
    // Square(mt_x + 81, mt_y + 37, 10, 10, '3',0,0,35,0,1);
    // Square(mt_x + 91, mt_y + 41, 50, 9, '3');
    Circle(mt_x + 116, mt_y + 43 + 5, 52, 9, '$', 0, -6, 2, -9, 1);//??

    //------------------------------------------------------------------------------------------------------
    //  End of editable section (or drawing calls)
    //------------------------------------------------------------------------------------------------------

    printCar(); // 저장된 그림 정보를 화면에 출력합니다.

    // main 함수의 반환 타입은 int가 표준입니다. void main() 대신 int main()을 사용하고 return 0;을 추가하는 것이 좋습니다.
}
