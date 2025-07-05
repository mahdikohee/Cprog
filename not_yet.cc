//A simple c++ code to make a cube
#include <iostream>
#include <cmath>
#include <unistd.h>
#include <vector>
#include <cstring>
using namespace std;

const int W = 100, H = 40;
const float DIST = 3.0f;
const float SCALE = 20.0f;

float A = 0.0f, B = 0.0f;

struct Vec3 {
    float x, y, z;
};

struct Vec2 {
    int x, y;
};

Vec3 rotate(Vec3 p, float A, float B) {
    float sinA = sin(A), cosA = cos(A);
    float sinB = sin(B), cosB = cos(B);

    float x = p.x * cosB + p.z * sinB;
    float z = -p.x * sinB + p.z * cosB;
    float y = p.y * cosA - z * sinA;
    z = p.y * sinA + z * cosA;

    return { x, y, z };
}

Vec2 project(Vec3 p) {
    float z = p.z + DIST;
    return {
        int(W / 2 + SCALE * p.x / z),
        int(H / 2 - SCALE * p.y / z)
    };
}

void drawLine(char *buffer, Vec2 a, Vec2 b, char ch) {
    int dx = abs(b.x - a.x), dy = abs(b.y - a.y);
    int sx = a.x < b.x ? 1 : -1;
    int sy = a.y < b.y ? 1 : -1;
    int err = dx - dy;

    while (true) {
        if (a.x >= 0 && a.x < W && a.y >= 0 && a.y < H)
            buffer[a.x + a.y * W] = ch;

        if (a.x == b.x && a.y == b.y) break;
        int e2 = 2 * err;
        if (e2 > -dy) { err -= dy; a.x += sx; }
        if (e2 < dx)  { err += dx; a.y += sy; }
    }
}

int main() {
    vector<Vec3> cube = {
        {-1, -1, -1}, {1, -1, -1},
        {1, 1, -1}, {-1, 1, -1},
        {-1, -1, 1}, {1, -1, 1},
        {1, 1, 1}, {-1, 1, 1}
    };

    int edges[12][2] = {
        {0,1},{1,2},{2,3},{3,0},
        {4,5},{5,6},{6,7},{7,4},
        {0,4},{1,5},{2,6},{3,7}
    };

    char buffer[W * H];

    printf("\x1b[2J"); // clear screen
    while (true) {
        memset(buffer, ' ', W * H);

        vector<Vec2> proj;
        for (auto &p : cube) {
            Vec3 r = rotate(p, A, B);
            proj.push_back(project(r));
        }

        for (auto &e : edges) {
            drawLine(buffer, proj[e[0]], proj[e[1]], '#');
        }

        printf("\x1b[H");
        for (int i = 0; i < W * H; ++i)
            putchar(i % W ? buffer[i] : '\n');

        A += 0.03f;
        B += 0.02f;
        usleep(30000);
    }

    return 0;
}

//Same code written in c 
#include <stdio.h>
#include <math.h>
#include <unistd.h>
#include <string.h>

#define W 100
#define H 40
#define DIST 3.0f
#define SCALE 20.0f

float A = 0.0f, B = 0.0f;

typedef struct {
    float x, y, z;
} Vec3;

typedef struct {
    int x, y;
} Vec2;

Vec3 rotate(Vec3 p, float A, float B) {
    float sinA = sinf(A), cosA = cosf(A);
    float sinB = sinf(B), cosB = cosf(B);

    float x = p.x * cosB + p.z * sinB;
    float z = -p.x * sinB + p.z * cosB;
    float y = p.y * cosA - z * sinA;
    z = p.y * sinA + z * cosA;

    Vec3 result = { x, y, z };
    return result;
}

Vec2 project(Vec3 p) {
    float z = p.z + DIST;
    Vec2 result = {
        (int)(W / 2 + SCALE * p.x / z),
        (int)(H / 2 - SCALE * p.y / z)
    };
    return result;
}

void drawLine(char *buffer, Vec2 a, Vec2 b, char ch) {
    int dx = abs(b.x - a.x), dy = abs(b.y - a.y);
    int sx = a.x < b.x ? 1 : -1;
    int sy = a.y < b.y ? 1 : -1;
    int err = dx - dy;

    while (1) {
        if (a.x >= 0 && a.x < W && a.y >= 0 && a.y < H)
            buffer[a.x + a.y * W] = ch;

        if (a.x == b.x && a.y == b.y) break;
        int e2 = 2 * err;
        if (e2 > -dy) { err -= dy; a.x += sx; }
        if (e2 < dx)  { err += dx; a.y += sy; }
    }
}

int main() {
    Vec3 cube[8] = {
        {-1, -1, -1}, {1, -1, -1},
        {1,  1, -1}, {-1, 1, -1},
        {-1, -1,  1}, {1, -1,  1},
        {1,  1,  1}, {-1, 1,  1}
    };

    int edges[12][2] = {
        {0,1},{1,2},{2,3},{3,0},
        {4,5},{5,6},{6,7},{7,4},
        {0,4},{1,5},{2,6},{3,7}
    };

    char buffer[W * H];

    printf("\x1b[2J"); // clear screen
    while (1) {
        memset(buffer, ' ', W * H);

        Vec2 proj[8];
        for (int i = 0; i < 8; ++i) {
            Vec3 r = rotate(cube[i], A, B);
            proj[i] = project(r);
        }

        for (int i = 0; i < 12; ++i) {
            drawLine(buffer, proj[edges[i][0]], proj[edges[i][1]], '#');
        }

        printf("\x1b[H"); // move cursor to top-left
        for (int i = 0; i < W * H; ++i)
            putchar(i % W ? buffer[i] : '\n');

        A += 0.03f;
        B += 0.02f;
        usleep(30000); // 30ms delay
    }

    return 0;
}
//again same code written in rust 
use std::f32::consts::PI;
use std::thread::sleep;
use std::time::Duration;
use std::io::{self, Write};

const W: usize = 100;
const H: usize = 40;
const DIST: f32 = 3.0;
const SCALE: f32 = 20.0;

#[derive(Copy, Clone)]
struct Vec3 {
    x: f32,
    y: f32,
    z: f32,
}

#[derive(Copy, Clone)]
struct Vec2 {
    x: i32,
    y: i32,
}

fn rotate(p: Vec3, a: f32, b: f32) -> Vec3 {
    let sin_a = a.sin();
    let cos_a = a.cos();
    let sin_b = b.sin();
    let cos_b = b.cos();

    let mut x = p.x * cos_b + p.z * sin_b;
    let mut z = -p.x * sin_b + p.z * cos_b;
    let y = p.y * cos_a - z * sin_a;
    z = p.y * sin_a + z * cos_a;

    Vec3 { x, y, z }
}

fn project(p: Vec3) -> Vec2 {
    let z = p.z + DIST;
    Vec2 {
        x: (W as f32 / 2.0 + SCALE * p.x / z) as i32,
        y: (H as f32 / 2.0 - SCALE * p.y / z) as i32,
    }
}

fn draw_line(buffer: &mut [char], a: Vec2, b: Vec2, ch: char) {
    let mut x0 = a.x;
    let mut y0 = a.y;
    let x1 = b.x;
    let y1 = b.y;

    let dx = (x1 - x0).abs();
    let dy = (y1 - y0).abs();
    let sx = if x0 < x1 { 1 } else { -1 };
    let sy = if y0 < y1 { 1 } else { -1 };
    let mut err = dx - dy;

    loop {
        if x0 >= 0 && x0 < W as i32 && y0 >= 0 && y0 < H as i32 {
            buffer[(x0 + y0 * W as i32) as usize] = ch;
        }
        if x0 == x1 && y0 == y1 {
            break;
        }
        let e2 = 2 * err;
        if e2 > -dy {
            err -= dy;
            x0 += sx;
        }
        if e2 < dx {
            err += dx;
            y0 += sy;
        }
    }
}

fn clear_screen() {
    print!("\x1b[2J");
}

fn move_cursor_home() {
    print!("\x1b[H");
}

fn main() {
    let cube = [
        Vec3 { x: -1.0, y: -1.0, z: -1.0 },
        Vec3 { x:  1.0, y: -1.0, z: -1.0 },
        Vec3 { x:  1.0, y:  1.0, z: -1.0 },
        Vec3 { x: -1.0, y:  1.0, z: -1.0 },
        Vec3 { x: -1.0, y: -1.0, z:  1.0 },
        Vec3 { x:  1.0, y: -1.0, z:  1.0 },
        Vec3 { x:  1.0, y:  1.0, z:  1.0 },
        Vec3 { x: -1.0, y:  1.0, z:  1.0 },
    ];

    let edges = [
        (0, 1), (1, 2), (2, 3), (3, 0),
        (4, 5), (5, 6), (6, 7), (7, 4),
        (0, 4), (1, 5), (2, 6), (3, 7),
    ];

    let mut a: f32 = 0.0;
    let mut b: f32 = 0.0;

    clear_screen();

    loop {
        let mut buffer = vec![' '; W * H];

        let mut projected = vec![Vec2 { x: 0, y: 0 }; 8];
        for (i, &p) in cube.iter().enumerate() {
            let rotated = rotate(p, a, b);
            projected[i] = project(rotated);
        }

        for &(start, end) in edges.iter() {
            draw_line(&mut buffer, projected[start], projected[end], '#');
        }

        move_cursor_home();
        for (i, ch) in buffer.iter().enumerate() {
            if i % W == 0 && i != 0 {
                println!();
            }
            print!("{}", ch);
        }

        io::stdout().flush().unwrap();

        a += 0.03;
        b += 0.02;

        sleep(Duration::from_millis(30));
    }
}

