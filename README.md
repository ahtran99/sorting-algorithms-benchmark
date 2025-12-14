<section id="c-assignment-3">
  <h1>Sorting Algorithms Benchmark (C)</h1>

  <h2>Description</h2>
  <p>
    A C program that compares the performance of four sorting algorithms by running them against two datasets,
    measuring execution time, and writing sorted results to output files.
  </p>

  <h2>Features</h2>
  <ul>
    <li>Implements and benchmarks: Selection Sort (G1), Bubble Sort (G2), Quick Sort (G3), Heap Sort (G4)</li>
    <li>Dataset 1: sorts values 1..n where n = 10,000 (already sorted) and prints timing to the screen</li>
    <li>Dataset 2: reads the first 10,000 values from <code>test_dat.txt</code> and outputs sorted results + timing to files</li>
    <li>Exports results to separate output files (e.g., <code>G1.txt</code>, <code>G2.txt</code>, <code>G3.txt</code>, <code>G4.txt</code>)</li>
  </ul>

  <h2>Tech Stack</h2>
  <ul>
    <li><strong>C</strong> &ndash; Arrays, file I/O, algorithm implementation</li>
    <li><strong>&lt;time.h&gt;</strong> &ndash; Timing execution using <code>clock()</code> / <code>CLOCKS_PER_SEC</code></li>
  </ul>

  <h2>What I Learned</h2>
  <ul>
    <li>Implementing multiple sorting algorithms and comparing trade-offs</li>
    <li>Measuring runtime performance in C using CPU clock timing</li>
    <li>Reading large datasets from files and writing results to multiple outputs</li>
    <li>Designing a repeatable benchmark workflow (same n, same measurement style)</li>
  </ul>

  <h2>Screenshots</h2>
  <p>
    Add 1&ndash;2 screenshots (or terminal captures) showing:
    <br />
    <em>(1) timing output for Dataset 1 and (2) generated output files for Dataset 2</em>
  </p>

  <h2>How to Run</h2>
  <ol>
    <li>
      Clone this repository:
      <pre><code>git clone https://github.com/ahtran99/C-Assignment3-repo.git</code></pre>
    </li>
    <li>
      Navigate to the project directory:
      <pre><code>cd C-Assignment3-repo</code></pre>
    </li>
    <li>
      Place <code>test_dat.txt</code> in the expected folder (for Dataset 2).
    </li>
    <li>
      Compile:
      <pre><code>gcc main.c -o sort_benchmark</code></pre>
    </li>
    <li>
      Run:
      <pre><code>./sort_benchmark</code></pre>
    </li>
  </ol>

  <h2>Notes</h2>
  <p>
    <strong>Originally built as part of a Sheridan College assignment.</strong><br />
    The assignment required benchmarking Selection/Bubble/Quick/Heap sort using a generated dataset and a file-based dataset,
    timing results, and exporting sorted outputs to separate files.
  </p>
</section>
