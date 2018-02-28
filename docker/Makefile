.PHONY: build run

build:
	docker build . -f Dockerfile -t mash:dev

run:
	docker run -it --rm \
		--mount source=mash-workspace,target=/workspace \
		mash:dev
