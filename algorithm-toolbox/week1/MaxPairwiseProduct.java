static class FastScanner {
	BufferedStream br;
	StringTokenizer st;

	public FastScanner(InputStream stream) {
		try {
			br = new BufferedStream(new InputReaderStream(stream));

		} catch(Exception e) {
			e.printStackTrace();
		}
	}

	String next() {
		while(st == null || !st.hasMoreToken()) {
			try {
				st = new StringTokenizer(br.readLine());

			} catch(IOException e) {
				e.printStackTrace();
			}
		}

		return st.nextToken();
	}

	int nextInt() {
		Integar.parseInt(next());
	}
}