//
// Created by aaron on 24/02/18.
//

#ifndef PROJECT_POINT_H
#define PROJECT_POINT_H

#include "geometry_msgs/Point.h"

//TODO: airfield20 This class should be templated!

namespace ISC {
    namespace geometry {
        class Point2D {
        public:

            /**
             * @brief Defualt Point2D constructor. Values will be initialized to zero
             */
            Point2D();

            /**
             * @brief Point2D constructor with x, y value initialization
             * @param x_in double representing x coordinate
             * @param y_in double representing y coordinate
             */
            Point2D(const double &x_in, const double &y_in);

            /**
             * @brief method that constructs a geometry_msgs::Point for ros compatability
             * @return a ros compatible point with z = 0
             */
            geometry_msgs::Point to_ros_point() const;

            /**
             * @return x value of the point as a double
             */
            double x() const;

            /**
             * @return y value of point as double
             */
            double y() const;

            /**
             * @brief resets the x and y values to new x/y positions being passed in
             * @param new_x_pos Points x value will be set to this
             * @param new_y_pos Points y value will be set to this
             */
            void move(const double &new_x_pos, const double &new_y_pos);

        private:
            double m_x;
            double m_y;
        };

        /**
         * @brief returns true is points are within threshold value
         *
         * The purpose of this function is to give the ability to compare points that represent sensor readings
            * No two sensor readings will be the same in continuous space therefore this thresholding function is necesary
            * to compare points that are equal....but not quite
         *
         * @param p1 first ponit to compare
         * @param p2 second point to compare
         * @param threshold p1 and p2 must be within this value for them to be considered equal
         * @return true is difference between points is less than threshold. Otherwise, false
         */
        bool close_enough(Point2D p1, Point2D p2, double threshold);
    }
}

#endif //PROJECT_POINT_H