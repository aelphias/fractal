for each pixel (x, y) on the screen, do:
    x := scaled x coordinate of pixel (scaled to lie in the Mandelbrot X scale (-2.5, 1))
    y := scaled y coordinate of pixel (scaled to lie in the Mandelbrot Y scale (-1, 1))

    zx := x // zx represents the real part of z
    zy := y // zy represents the imaginary part of z 

    iteration := 0
    max_iteration := 1000
  
    while (zx*zx + zy*zy < 4 and iteration < max_iteration) do
        xtemp := zx*zx - zy*zy + x 
        zy := abs(2*zx*zy) + y // abs returns the absolute value
        zx := xtemp
        iteration := iteration + 1

    if iteration = max_iteration then // Belongs to the set
        return insideColor

    return iteration × color