#version 120
attribute highp vec4 posAttr;

varying lowp vec4 col;

uniform lowp vec4 color;
uniform highp mat4 matrix;
uniform highp float morph;

void main() {
    col = color;
    vec4 r_n = vec4(normalize(posAttr.xyz), 1.0);
    gl_Position = matrix * (morph * posAttr + (1 - morph) * r_n);
}