#version 120

attribute highp vec4 posAttr;

varying highp vec4 pos;
varying highp vec2 uv;

uniform highp mat4 perspMatrix;
uniform highp mat4 transCamMatrix;

void main() {
    pos = posAttr;
    uv = vec2(posAttr.x, -posAttr.z);

    gl_Position = perspMatrix * transCamMatrix * pos;
}
