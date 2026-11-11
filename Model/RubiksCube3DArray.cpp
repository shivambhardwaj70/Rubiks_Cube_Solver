#include "GenericRubiksCube.h"

class RubiksCube3DArray : public GenericRubiksCube {

private:
    void rotateFace(int ind) {
        char temp_arr[3][3] = {};
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                temp_arr[i][j] = cube[ind][i][j];
            }
        }
        for (int i = 0; i < 3; i++) cube[ind][0][i] = temp_arr[2 - i][0];
        for (int i = 0; i < 3; i++) cube[ind][i][2] = temp_arr[0][i];
        for (int i = 0; i < 3; i++) cube[ind][2][2 - i] = temp_arr[i][2];
        for (int i = 0; i < 3; i++) cube[ind][2 - i][0] = temp_arr[2][2 - i];
    }

public:
    char cube[6][3][3]{};
    RubiksCube3DArray() {
        for (int i=0;i<6;i++) {
            for (int j=0;j<3;j++) {
                for (int k=0;k<3;k++) {
                    cube[i][j][k]=getColorLetter(static_cast<COLOR>(i));
                }
            }
        }
    }

    COLOR getColor(FACE face, int row, int col) const override{
        char color=cube[static_cast<int>(face)][row][col];
        switch (color) {
            case 'B':
                return COLOR::BLUE;
            case 'R':
                return COLOR::RED;
            case 'G':
                return COLOR::GREEN;
            case 'Y':
                return COLOR::YELLOW;
            case 'O':
                return COLOR::ORANGE;
            default:
                return COLOR::WHITE;
        }
    }

    void setColor(FACE face, int row, int col, COLOR color) override {
        cube[static_cast<int>(face)][row][col]=getColorLetter(color);
    }

    bool isSolved() const override {
        for (int i=0;i<6;i++) {
            for (int j=0;j<3;j++) {
                for (int k=0;k<3;k++) {
                    if (getColorLetter(static_cast<COLOR>(i))!=this->cube[i][j][k]) {
                        return false;
                    }
                }
            }
        }
        return true;
    }

    GenericRubiksCube &u() override {
        this->rotateFace(0);

        char temp_arr[3]{};
        for (int i=0;i<3;i++) temp_arr[i]=cube[4][0][2-i];
        for (int i=0;i<3;i++) cube[4][0][2-i]=cube[1][0][2-i];
        for (int i=0;i<3;i++) cube[1][0][2-i]=cube[2][0][2-i];
        for (int i=0;i<3;i++) cube[2][0][2-i]=cube[3][0][2-i];
        for (int i=0;i<3;i++) cube[3][0][2-i]=temp_arr[i];

        return *this;
    }

    GenericRubiksCube &uprime() override {
        this->u().u().u();

        return *this;
    }

    GenericRubiksCube &u2() override {
        this->u().u();
        return *this;
    }


    GenericRubiksCube &l() override {
        this->rotateFace(1);
        char temp_arr[3]{};
        for (int i = 0; i < 3; i++) temp_arr[i] = cube[0][i][0];
        for (int i = 0; i < 3; i++) cube[0][i][0] = cube[4][2 - i][2];
        for (int i = 0; i < 3; i++) cube[4][2 - i][2] = cube[5][i][0];
        for (int i = 0; i < 3; i++) cube[5][i][0] = cube[2][i][0];
        for (int i = 0; i < 3; i++) cube[2][i][0] = temp_arr[i];

        return *this;
    }

    GenericRubiksCube &lprime() override {
        this->l().l().l();
        return *this;
    }
    GenericRubiksCube &l2() override {
        this->l().l();
        return *this;
    }

    GenericRubiksCube &f() override {
        this->rotateFace(2);

        char temp_arr[3] = {};
        for (int i = 0; i < 3; i++) temp_arr[i] = cube[0][2][i];
        for (int i = 0; i < 3; i++) cube[0][2][i] = cube[1][2 - i][2];
        for (int i = 0; i < 3; i++) cube[1][2 - i][2] = cube[5][0][2 - i];
        for (int i = 0; i < 3; i++) cube[5][0][2 - i] = cube[3][i][0];
        for (int i = 0; i < 3; i++) cube[3][i][0] = temp_arr[i];

        return *this;
    }

    GenericRubiksCube &fprime() override {
        this->f().f().f();

        return *this;
    }

    GenericRubiksCube &f2() override {
        this->f().f();
        return *this;
    }


    GenericRubiksCube &r() override {
        this->rotateFace(3);

        char temp_arr[3] = {};
        for (int i = 0; i < 3; i++) temp_arr[i] = cube[0][2 - i][2];
        for (int i = 0; i < 3; i++) cube[0][2 - i][2] = cube[2][2 - i][2];
        for (int i = 0; i < 3; i++) cube[2][2 - i][2] = cube[5][2 - i][2];
        for (int i = 0; i < 3; i++) cube[5][2 - i][2] = cube[4][i][0];
        for (int i = 0; i < 3; i++) cube[4][i][0] = temp_arr[i];

        return *this;
    }

    GenericRubiksCube &rprime() override {
        this->r().r().r();

        return *this;
    }

    GenericRubiksCube &r2() override {
        this->r().r();
        return *this;
    }

    GenericRubiksCube &b() override {
        this->rotateFace(4);

        char temp_arr[3] = {};
        for (int i = 0; i < 3; i++) temp_arr[i] = cube[0][0][2 - i];
        for (int i = 0; i < 3; i++) cube[0][0][2 - i] = cube[3][2 - i][2];
        for (int i = 0; i < 3; i++) cube[3][2 - i][2] = cube[5][2][i];
        for (int i = 0; i < 3; i++) cube[5][2][i] = cube[1][i][0];
        for (int i = 0; i < 3; i++) cube[1][i][0] = temp_arr[i];

        return *this;
    }

    GenericRubiksCube &bprime() override {
        this->b().b().b();

        return *this;
    }

    GenericRubiksCube &b2() override {
        this->b().b();
        return *this;
    }


    GenericRubiksCube &d() override {
        this->rotateFace(5);

        char temp_arr[3] = {};
        for (int i = 0; i < 3; i++) temp_arr[i] = cube[2][2][i];
        for (int i = 0; i < 3; i++) cube[2][2][i] = cube[1][2][i];
        for (int i = 0; i < 3; i++) cube[1][2][i] = cube[4][2][i];
        for (int i = 0; i < 3; i++) cube[4][2][i] = cube[3][2][i];
        for (int i = 0; i < 3; i++) cube[3][2][i] = temp_arr[i];

        return *this;
    }

    GenericRubiksCube &dprime() override {
        this->d().d().d();

        return *this;
    }

    GenericRubiksCube &d2() override {
        this->d().d();
        return *this;
    }

    bool operator==(const RubiksCube3DArray& r1) const {
        for (int i = 0; i < 6; i++) {
            for (int j = 0; j < 3; j++) {
                for (int k = 0; k < 3; k++) {
                    if (r1.cube[i][j][k]!=cube[i][j][k]) return false;
                }
            }
        }
        return true;
    }
    RubiksCube3DArray &operator=(const RubiksCube3DArray& r1) {
        for (int i = 0; i < 6; i++) {
            for (int j = 0; j < 3; j++) {
                for (int k = 0; k < 3; k++) {
                    cube[i][j][k]=r1.cube[i][j][k];
                }
            }
        }
        return *this;
    }
};

struct Hash3d {
    size_t operator()(const RubiksCube3DArray &r1) const {
        string str="";
        for (int i = 0; i < 6; i++) {
            for (int j = 0; j < 3; j++) {
                for (int k = 0; k < 3; k++) {
                    str += r1.cube[i][j][k];
                }
            }
        }
        return hash<string>()(str);
    }

};