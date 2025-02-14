
// ex01
function shapes(){
    let trapezoid = document.createElement("canvas");
    let diamond = document.createElement("canvas");
    let zigzagging = document.createElement("canvas"); 
    let spiral = document.createElement("canvas");
    let star = document.createElement("canvas");

    trapezoid.width="600";
    diamond.width="600";
    zigzagging.width="600";
    spiral.width="600";
    star.width="600";

    trapezoid.height="200";
    diamond.height="200";
    zigzagging.height="200";
    spiral.height="200";
    star.height="200";

    function trape(ctx,x,y,a,b,h) {
        ctx.strokeSTyle = "red";
        ctx.beginPath();
        ctx.moveTo(x, y);
        ctx.lineTo(x + a, y);
        ctx.lineTo(x + (b - a) / 2, y + h);
        ctx.lineTo(x + a + (b - a) / 2, y + h);
        ctx.closePath();
        ctx.fill();
        ctx.stroke();
    }
    function diamonds(ctx,cx,cy,s) {
        ctx.strokeStyle = "blue";
        ctx.beginPath();
        ctx.moveTo(cx, cy - s);
        ctx.lineTo(cx + s, cy);
        ctx.lineTo(cx, cy + s);
        ctx.lineTo(cx - s, cy);
        ctx.closePath();
        ctx.fill();
        ctx.stroke();
    }
    function drawZigzag(ctx, x, y, length, h, n){
        ctx.strokeStyle = "orange";
        ctx.beginPath();
    
        ctx.stroke();
    }
    function drawSpiral(ctx, cx, cy, a, b, maxAngle){
        ctx.strokeStyle = "green";
        ctx.beginPath(); 
    }
    function drawStar(ctx, cx, cy, radiusOuter, radiusInner, n){
        ctx.strokeStyle = "yellow";
        ctx.beginPath();
    }
    trape(trapezoid,100,100,50,20,60);
    diamonds(diamond,);
    drawZigzag(zigzagging,);
    drawSpiral(spiral,);
    drawStar(star,);
}
// shapes();

// ex02
function pie_chart(){
    let cx = document.querySelector("canvas").getContext("2d");
  let total = results
    .reduce((sum, {count}) => sum + count, 0);
  let currentAngle = -0.5 * Math.PI;
  let centerX = 300, centerY = 150;

  // Add code to draw the slice labels in this loop.
  let middleAngle = currentAngle + 0.5 * sliceAngle;
  let textX = Math.cos(middleAngle) * 120 + centerX;
  let textY = Math.sin(middleAngle) * 120 + centerY;
  let text = document.createElement("p");
  text.fillText = "name of chart";
  text.textAlign = textX + textY;
  text.textBaseline = textX - textY;
  for (let result of results) {
    let sliceAngle = (result.count / total) * 2 * Math.PI;

    cx.beginPath();
    cx.arc(centerX, centerY, 100,
           currentAngle, currentAngle + sliceAngle);
    currentAngle += sliceAngle;
    cx.lineTo(centerX, centerY);
    cx.fillStyle = result.color;
    cx.fill();
  }
}

// ex03
function bouncingBall() {
  const canvas = document.getElementById('bouncingBallCanvas');
  const ctx = canvas.getContext('2d');
  // Ball properties
  const radius = 20;
  let x = canvas.width / 2;
  let y = canvas.height / 2;
  let dx = 2; // Horizontal speed
  let dy = 2; // Vertical speed
  // Animation loop
  function frame() {
    // Clear the canvas
    ctx.clearRect(0, 0, canvas.width, canvas.height);
    // Draw the ball
    ctx.beginPath();
    ctx.arc(x, y, radius, 0, Math.PI * 2);
    ctx.fillStyle = 'red';
    ctx.fill();
    ctx.closePath();
    // Update ball position
    x += dx;
    y += dy;
    // Collision detection with walls
    if (x + radius > canvas.width || x - radius < 0) {
      dx = -dx; // Reverse horizontal direction
    }
    if (y + radius > canvas.height || y - radius < 0) {
      dy = -dy; // Reverse vertical direction
    }
    // Request the next frame
    requestAnimationFrame(frame);
  }
  // Start the animation
  frame();
}
// bouncingBall();

/**Questions: Think of a way to draw an inverted character without loading additional image files and
 *  without having to make transformed drawImage calls every frame. 
 * 
 * Answer to ex04: 
 * The key to the solution is the fact that we can use a canvas element as a source image when using drawImage.
 *  It is possible to create an extra <canvas> element, without adding it to the document, and draw our inverted sprites to it, once.
 *  When drawing an actual frame, we just copy the already inverted sprites to the main canvas.
 * 
 *  A "load" handler on the image can be used to draw the inverted images to the extra canvas.
 *  This canvas can be used as a drawing source immediately
 * 
 * 
 * 
 * 
 * 
 */
