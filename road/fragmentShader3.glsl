#version 120
varying highp vec4 pos;
varying highp vec2 uv;

uniform highp vec3 directedDir;
uniform lowp vec3 directedCol;

uniform sampler2D textureRoad1;
uniform sampler2D textureRoad2;
uniform sampler2D textureRoad3;


vec3 calcNormalFromNormalmap(vec3 localNormal, vec2 uv)
{
    vec3 n = normalize( localNormal.xyz );
    vec3 t = normalize( cross(n, vec3(0,0,1)) );
    vec3 b = cross(t, n);

    vec3 trash = texture2D( textureRoad2, uv ).rgb + texture2D( textureRoad3, uv ).rgb + pos.xyz;
    vec3 normal = texture2D( textureRoad1, uv ).rgb + 0*trash;
    normal = normalize( normal * 2.0 - 1.0 );

    vec3 resultingNormal = normalize( normal.x * t + normal.y * b + normal.z * n );

    return resultingNormal*0 + n;
}


void main() {
    vec3 n = vec3(0,1,0);
    vec3 col1 = texture2D( textureRoad1, uv ).rgb;
    vec3 col2 = texture2D( textureRoad2, uv * 2 ).rgb;
    vec3 col3 = texture2D( textureRoad3, uv ).rgb;
    vec3 col = mix(col2, col1, 0.8) * col3;
//    vec3 col = col2;

    vec3 dir_diffuse = vec3(0.0, 0.0, 0.0);
    if (length(directedDir) > 1e-5)
    {
        vec3 l = normalize(-directedDir);

        dir_diffuse = directedCol * max(0, dot(l, n.xyz));
    }

    vec3 temp_col = dir_diffuse;

    gl_FragColor = vec4(temp_col * col, 1.0);
}
