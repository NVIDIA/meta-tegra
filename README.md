# NVIDIA meta-tegra (control branch)

This `main` branch is the **NVIDIA control branch** for [NVIDIA/meta-tegra](https://github.com/NVIDIA/meta-tegra).

It is intentionally separate from OE4T content branches (`master`, `wrynose`, Yocto release lines, etc.).

## Purpose

- Host GitHub Actions that keep OE4T branches mirrored into this fork
- Remain the repository **default branch** so scheduled workflows can run
- Never receive OE4T content syncs (protected by the sync workflow)

## Branch policy

| Branch | Role |
|--------|------|
| `main` | NVIDIA control (this branch); Actions only |
| `master`, `wrynose`, `scarthgap`, … | Mirrors of [OE4T/meta-tegra](https://github.com/OE4T/meta-tegra) |
| `master+*` | NVIDIA-only integration branches; never overwritten by sync |

## Sync workflow

`.github/workflows/sync-upstream.yml` runs daily (and on manual dispatch) and mirrors upstream OE4T branches onto this repository, skipping `main` and `master+*`.

After pushing this branch, set **Settings → General → Default branch** to `main`.
