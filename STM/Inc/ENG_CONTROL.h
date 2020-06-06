#ifndef ENGINE_CONTROL_H_
#define ENGINE_CONTROL_H_

//SPEED FUNCTION
void ENG_right_turn(void);
void check_and_set_period(int ccr);
void check_and_set_period_2(int ccr1, int ccr2);

//BASIC FUNCTION :
void ENG_forward(void);
void ENG_back(void); // UNUSED
void ENG_left(void);
void ENG_left_turn(void);
void ENG_right(void);
void ENG_right_turn(void);
void ENG_break_(void);

//Complex functions
void ENG_choose(int choose);
void ENG_just_a_turn(int choose);

#endif
