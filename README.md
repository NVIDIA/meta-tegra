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
| `master`, `wrynose`, `whinlatter`, `walnascar`, `scarthgap`, `nanbield` | Allowlisted mirrors of [OE4T/meta-tegra](https://github.com/OE4T/meta-tegra) |
| `master+*` | NVIDIA-only integration branches; never overwritten by sync |

## Sync workflow

`.github/workflows/sync-upstream.yml` runs every 5 minutes (and on manual dispatch) and mirrors only the allowlisted OE4T branches above. Edit the `BRANCHES` array in that workflow to add or remove lines.

After pushing this branch, set **Settings → General → Default branch** to `main`.
