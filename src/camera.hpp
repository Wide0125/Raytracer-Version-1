#ifndef CUSTOMCAMERA_H
#define CUSTOMCAMERA_H
#include "line.hpp"

namespace Custom {
    class Camera {
        public:
            constexpr const Point& pos() const {return m_pos;}

            constexpr double viewportWidth() const {return m_viewportWidth;}
            constexpr double viewportHeight() const {return m_viewportHeight;}

            constexpr int screenWidth() const {return m_screenWidth;}
            constexpr int screenHeight() const {return m_screenHeight;}

        private:
            Point m_pos {0, 0, 0};
            int m_screenWidth {960};
            int m_screenHeight {540};
            
            double m_viewportDistanceFromCamera {1};
            double m_viewportHeight {1};
            double m_viewportWidth {m_viewportHeight/m_screenHeight * m_screenWidth};
    };
}

inline constexpr Line getPixelLine(int pixelX, int pixelY, const Custom::Camera& camera) {

    double xDistanceFromCenter {camera.viewportWidth()/camera.screenWidth() * -(pixelX - camera.screenWidth()/2)};
    double yDistanceFromCenter {camera.viewportHeight()/camera.screenHeight() * -(pixelY - camera.screenHeight()/2)};

    return {camera.pos(), {xDistanceFromCenter, yDistanceFromCenter, 1}};
} // get vector from origin to pixel's equivalent location on viewport


#endif
