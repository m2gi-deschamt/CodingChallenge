const BACKGROUND = "black";
const FOREGROUND = "green";
const WIDTH = 800;
const HEIGHT = 800;

console.log(game);
game.width = WIDTH;
game.height = HEIGHT;
const ctx = game.getContext("2d");
console.log(ctx);
function clear() {
  ctx.fillStyle = BACKGROUND;
  ctx.fillRect(0, 0, game.width, game.height);
}

function point({ x, y }) {
  const s = 20;
  ctx.fillStyle = FOREGROUND;
  ctx.fillRect(x - s / 2, y - s / 2, s, s);
}

function line(p1, p2) {
  ctx.lineWidth = 3;
  ctx.strokeStyle = FOREGROUND;
  ctx.beginPath();
  ctx.moveTo(p1.x, p1.y);
  ctx.lineTo(p2.x, p2.y);
  ctx.stroke();
}

function screen(p) {
  return {
    x: ((p.x + 1) / 2) * game.width,
    y: (1 - (p.y + 1) / 2) * game.height,
  };
}

function project({ x, y, z }) {
  return {
    x: x / z,
    y: y / z,
  };
}

function rotate_xz({ x, y, z }, angle) {
  const c = Math.cos(angle);
  const s = Math.sin(angle);
  return {
    x: x * c - z * s,
    y,
    z: x * s + z * c,
  };
}

const FPS = 60;
let dz = 1;
let angle = 0;

function translate_z({ x, y, z }, dz) {
  return { x, y, z: z + dz };
}

function frame() {
  const dt = 1 / (FPS * 4);
  //dz += 1 * dt;
  angle += 2 * Math.PI * dt;
  clear();

  for (const f of fs) {
    for (let i = 0; i < f.length; ++i) {
      const a = vs[f[i]];
      const b = vs[f[(i + 1) % f.length]];
      line(
        screen(project(translate_z(rotate_xz(a, angle), dz))),
        screen(project(translate_z(rotate_xz(b, angle), dz))),
      );
    }
  }

  setTimeout(frame, 1000 / FPS);
}

setTimeout(frame, 1000 / FPS);
