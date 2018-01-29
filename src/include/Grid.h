#pragma once

#include "BasicTypes.h"

enum class GRID_TYPE {
    LINEAR,
    TRIGONOMETRIC,
    LIN_TRIG_LEFT,
    LIN_TRIG_RIGHT,
    SHIFTED
};

class Grid {
    public:
        Grid(size_t N, size_t addNCount = 11);

        // �������� ������ ������� �����
        BmpVector base() const;

        // �������� ������ �������������� ����� (������ � ��������)
        BmpVector additional() const;

        // �������� x �� y
        BmpVector xByY(const BmpVector& y);

        // ���������� ����� ������� ����� �� ��������� ������
        void setLinearGrid();

        /**
         * ������ ������ �������-������������������ ����� � ������� ����� �����, ���� m_additionalNCount
         * �������������� ����� ����� ������ ����� ������� �����.
         * ��������� ��� ��� ������������� ������������� ����� � ��������� ��������.
         */
        void setLinearTrigonometricGrid();

        /**
         * ������ ������ �������-������������������ ����� � ������� ����� ������, ���� m_additionalNCount
         * �������������� ����� ����� ������ ����� ������� �����.
         * ��������� ������ ��� ��������� ��������.
         */
        void setLinearTrigonometricGridRight();

        /**
         * ������ ����������. ������������ ����� � �������������� ������������� �����������.
         * ksi = 1/y; delta - ����������, ���������� �� ����� � ksi.
         * eta(i) = ksi(i) + 0.5*(ksi(i+1)-ksi(i-1))*tau*(1+sqrt(delta(i-0.5)/delta(i+0.5)))/(1-sqrt(delta(i-0.5)/delta(i+0.5)))
         * tau = 0.5
         */
        void shiftLinTrigGrid(const BmpVector& delta, BmpReal tau);

        /**
        * �������� ������ ���������� ����������� �� ���������� ������� �����.
        * ����� ��������������� ������� ��� ������������ �������� ����� ��� ������������ �����������.
        * ������������ ����� ��������� �����������, ����� shiftLinTrigGrid()
        */
        BmpVector intervalMaximums();

    private:
        // ����� ������� �����
        size_t m_N_base;
        // ����� �������������� ����� ����� ��������
        size_t m_additionalNCount;
        // ������ ������� �����
        BmpVector m_base;
        // ������ �������������� �����
        BmpVector m_additional;

        /* ��������� ����� ��������������� ������� */
        void setAdditionalDots();

        /**
         * � �������������� ������������� ��� ����������� ������������� ����� ������������
         * ������������ ������ ���������� ksi = 1/y. �� ������ �������� ��������� � ����� ������� �� ���������� y
         * ( ������ ������ �� x = ln(exp(y) - 1) ). ������� ����� ��������������� ��������������� �������.
         */
        /* ��������� ������ ���������� y = 1/ksi */
        void changeGrid(BmpVector& v);
};
