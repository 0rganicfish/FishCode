/**
 * Copyright (C) Fish
 *
 * xxx some some some
 *
 * @file Class.hpp
 * @author Fish
 * @version 0.0.1
 * @date 2022/20/22
 * @brief This file ... just is a file
 */

/** @brief Fish's class */
namespace Fish
{
    const double PI = acos(-1);

    /**
     * @brief 这是一个 circle 类.
     */
    class Circle
    {
    private:
        double rad, area;

    public:
        double get_rad() { return rad; };
        double get_area() { return area; };
        void push();
        void calc();
        void print();
    };

    /** @brief 输入半径 */
    void Circle::push()
    {
        scanf("%lf", &rad);
    }

    /**
     * @brief 计算 圆 的面积
     * @param none
     * @return no return
     */
    void Circle::calc()
    {
        area = rad * rad * PI;
    }

    /** @brief 输出 圆 的半径及面积 */
    void Circle::print()
    {
        printf("Radius: %.2f, area: %.2f.\n", rad, area);
    }

    /** @brief sort 中的 cmp，以 area 小到大排序 */
    bool cmp_area(Circle x, Circle y)
    {
        return x.get_area() < y.get_area();
    }
};