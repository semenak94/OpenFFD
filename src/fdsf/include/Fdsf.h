/*
 * ������� ������������ ������������ ����
 */
#pragma once

#include "BasicTypes.h"

namespace fdsf {

    /* ������� �� ������ ������� */
    BmpReal fd_0(BmpReal x);
    BmpReal fd_1(BmpReal x);
    BmpReal fd_2(BmpReal x);
    BmpReal fd_3(BmpReal x);
    BmpReal fd_4(BmpReal x);

    /* ������� �� ���������� ������� */
    BmpReal fd_m3half(BmpReal x);
    BmpReal fd_m1half(BmpReal x);
    BmpReal fd_1half(BmpReal x);
    BmpReal fd_3half(BmpReal x);
    BmpReal fd_5half(BmpReal x);
    BmpReal fd_7half(BmpReal x);

    /* ������������ ������� �� */
    BmpReal fd_J(BmpReal x);

    /* ���������� ������������� ������� �� 2-�������� �������� � ��������� single precision */
    namespace single_prec {
        /* ������� �� ���������� ������� */
        BmpReal fd_m3half(BmpReal x);
        BmpReal fd_m1half(BmpReal x);
        BmpReal fd_1half(BmpReal x);
        BmpReal fd_3half(BmpReal x);
        BmpReal fd_5half(BmpReal x);
        BmpReal fd_7half(BmpReal x);
    }

    /* ���������� ���������� ������� �� � ������� ������������ ������������� */
    namespace prec_approx {
        /* ������� �� ������ ������� */
        BmpReal fd_0(BmpReal x);
        BmpReal fd_1(BmpReal x);
        BmpReal fd_2(BmpReal x);
        BmpReal fd_3(BmpReal x);
        BmpReal fd_4(BmpReal x);

        /* ������� �� ���������� ������� */
        BmpReal fd_m3half(BmpReal x);
        BmpReal fd_m1half(BmpReal x);
        BmpReal fd_1half(BmpReal x);
        BmpReal fd_3half(BmpReal x);
        BmpReal fd_5half(BmpReal x);
        BmpReal fd_7half(BmpReal x);
    }

    /* ���������� ���������� ������� �� � ������� ���������� ������������� */
    namespace global_approx {
        /* ���������� ����������� */
        namespace improved_asympt {
            /* ������� �� ������ ������� */
            BmpReal fd_1(BmpReal x);
            BmpReal fd_2(BmpReal x);
            BmpReal fd_3(BmpReal x);
            BmpReal fd_4(BmpReal x);

            /* ������� �� ���������� ������� */
            BmpReal fd_m3half(BmpReal x);
            BmpReal fd_m1half(BmpReal x);
            BmpReal fd_1half(BmpReal x);
            BmpReal fd_3half(BmpReal x);
            BmpReal fd_5half(BmpReal x);
            BmpReal fd_7half(BmpReal x);
        }

        /* ������������������ ����������� */
        namespace low_temp {
            /* ������� �� ������ ������� */
            BmpReal fd_1(BmpReal x);
            BmpReal fd_2(BmpReal x);
            BmpReal fd_3(BmpReal x);
            BmpReal fd_4(BmpReal x);

            /* ������� �� ���������� ������� */
            BmpReal fd_m3half(BmpReal x);
            BmpReal fd_m1half(BmpReal x);
            BmpReal fd_1half(BmpReal x);
            BmpReal fd_3half(BmpReal x);
            BmpReal fd_5half(BmpReal x);
            BmpReal fd_7half(BmpReal x);
        }

        /* ��������� �������� */
        namespace best_prec {
            /* ������� �� ������ ������� */
            BmpReal fd_1(BmpReal x);
            BmpReal fd_2(BmpReal x);
            BmpReal fd_3(BmpReal x);
            BmpReal fd_4(BmpReal x);

            /* ������� �� ���������� ������� */
            BmpReal fd_m3half(BmpReal x);
            BmpReal fd_m1half(BmpReal x);
            BmpReal fd_1half(BmpReal x);
            BmpReal fd_3half(BmpReal x);
            BmpReal fd_5half(BmpReal x);
            BmpReal fd_7half(BmpReal x);
        }
    }
}
