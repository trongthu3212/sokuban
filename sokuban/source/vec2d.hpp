struct vec2d {
    int x,y;
    vec2d (int x_, int y_){
        x=x_;
        y=y_;
    }
    float length();
    vec2d operator + (vec2d vephai);
    vec2d operator - (vec2d vephai);
};
